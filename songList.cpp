//Martha Sander - Class songList implementation.

#include "songList.h"


//SongList constructors.
SongList::SongList()
{
	capacity = CAP;
	
	myList = new Song[capacity]; 
	size = 0;
}

SongList::SongList(char fileName[])
{
	ifstream inFile;
	char artistInput[MAX], titleInput[MAX], albumInput[MAX];
	int minInput = 0, secInput = 0;
	Song mySong;
	capacity = CAP;
	
	myList = new Song[capacity];
	size = 0;

	inFile.open(fileName);
	if (! inFile.is_open())
	{
		cout << "File is not open. Please review information and try again." << endl;
		exit(0);
	}
	cout << "file " << fileName << " successfully opened!" << endl << endl;
	inFile.get(titleInput, MAX, ';');
	inFile.ignore (100, ';');
	inFile.get(artistInput, MAX, ';'); 
	inFile.ignore (100, ';');
	inFile >> minInput;
	inFile.ignore (100, ';');
	inFile >> secInput;
	inFile.ignore(100, ';');
	inFile.get(albumInput, MAX, '\n');
	inFile.ignore(100, '\n');
	//add information to song.
	mySong.setTitle(titleInput);
	mySong.setArtist(artistInput);
	mySong.setMin(minInput);
	mySong.setSec(secInput);
	mySong.setAlbum(albumInput);

	while((size < capacity) && (!inFile.eof()))
	{
		//add information to list.
		size++;
		addSong(mySong);
		inFile.get(titleInput, MAX, ';');
		inFile.ignore (100, ';');
		inFile.get(artistInput, MAX, ';'); 
		inFile.ignore (100, ';');
		inFile >> minInput;
		inFile.ignore (100, ';');
		inFile >> secInput;
		inFile.ignore(100, ';');
		inFile.get(albumInput, MAX, '\n');
		inFile.ignore(100, '\n');
		mySong.setTitle(titleInput);
		mySong.setArtist(artistInput);
		mySong.setMin(minInput);
		mySong.setSec(secInput);
		mySong.setAlbum(albumInput);
	}
	inFile.close();
}

void SongList::addSong(const Song &mySong)
{
	myList[size-1].setSong(mySong);
}

//SongList destructor.
SongList::~SongList()
{
	if (myList)
	{
		delete [] myList;
		myList = NULL;
	}
}	

int SongList::getSize()
{
	return size;
}

void SongList::searchByArtist(char returnArtist[])
{
	char artistInput[MAX];
	int count = 0;

	cout << "Search artist name: ";
	cin.getline(artistInput, MAX, '\n');

	for(int i = 0; i < size; i++)
	{
		myList[i].getArtist(returnArtist);
		if (strcasestr(returnArtist, artistInput))
		{
			cout << "*********************" << endl;
			cout << "Index: " << i+1 << endl;
			myList[i].printSong();
			count++;
		}
	}
	//print number of songs found by artist. If 0 songs found, print 0.
	cout << "Number of songs by " << artistInput << " found at your songs library: " << count << endl << endl;
}

void SongList::searchByAlbum(char returnAlbum[])
{
	char albumInput[MAX];
	int count = 0;
	
	cout << "Search album name: ";
	cin.getline(albumInput, MAX, '\n');

	for (int i = 0; i < size; i++)
	{
		myList[i].getAlbum(returnAlbum);
		if (strcasestr(returnAlbum, albumInput))
		{
			cout << "**********************" << endl;
			cout << "Index: " << i+1 << endl;
			myList[i].printSong();
			count++;
		}
	}
	cout << "Number of songs for album containing " << albumInput << " : " << count << endl << endl;
}

void SongList::printAllSongs()
{
	cout << "These are all the songs in your library:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "************************" << endl;
		cout << "Index: " << i+1 << endl;
		myList[i].printSong();
		cout << "************************" << endl;
	}
}

void SongList::removeSong()
{
	int userIndex, min, sec;
	Song mySong;

	cout << "Please enter index of the song to be removed: ";
	cin >> userIndex;
	userIndex = userIndex-1;
	
	if (userIndex >= size)
	{
		cout << "No song at index selected. Please try again!" << endl;
		exit(0);
	}
	for (int i = userIndex; i < size-1; i++)
	{
		myList[i].setSong(myList[i+1]);
	}
	size--;	
	cout << "Song removed from library" << endl << endl;
	cin.ignore(MAX, '\n');
}

void SongList::saveFile(char fileName[], char returnTitle[], char returnArtist[], char returnAlbum[])
{
	ofstream outFile;
	int min, sec;

	outFile.open(fileName);
	if (! outFile.is_open())
	{
		cout << "file is not open. Please review information and try again." << endl;
		exit(0);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{ 
			myList[i].getTitle(returnTitle);
			outFile << returnTitle << ";";
			myList[i].getArtist(returnArtist);
			outFile << returnArtist << ";";
			min = myList[i].getMin();
			outFile << min << ";"; 
			sec = myList[i].getSec();
			outFile << sec << ";";
			myList[i].getAlbum(returnAlbum);
			outFile << returnAlbum << endl;
		}
	}
	cout << endl;
	cout << "Library saved!" << endl << endl;
	outFile.close();
}

void SongList::addInput(Song &mySong)
{
	char titleInput[MAX], artistInput[MAX], albumInput[MAX];
	char userChoice;
	int minInput = 0, secInput = 0;

	cout << "Please add song to be added to the library" << endl;
	cout << "Title: ";
	cin.getline(titleInput, MAX, '\n');
	cout << "Artist: ";
	cin.getline(artistInput, MAX, '\n');
	cout << "Duration minutes (space) seconds: ";
	cin >> minInput;
	if(!cin)
	{
		while(!cin)
		{
			cout << "Bad input. Add integers only" << endl;
			cin.clear();
			cin.ignore(10, '\n');
	
			cout << "Duration minutes (space) seconds: ";
			cin >> minInput;
		}
	}
	cin.ignore();
	cin >> secInput;
	if(!cin)
	{
		while(!cin)
		{
			cout << "Bad input. Add integers only" << endl;
			cin.clear();
			cin.ignore(10, '\n');
	
			cout << "Duration minutes (space) seconds: ";
			cin >> secInput;
		}
	}
	cin.clear();
	cin.ignore(10, '\n');
	cout << "Album: ";
	cin.getline(albumInput, MAX, '\n');

	//echo information for validation.
	cout << "**********************" << endl;
	cout << "You entered: " << endl;
	cout << "Title: " << titleInput << endl;
	cout << "Artist: " << artistInput << endl;
	cout << "Duration: " << minInput << ":" << secInput << endl;
	cout << "Album: " << albumInput << endl << endl;
	cout << "**********************" << endl;

	do
	{
		cout << "Do you want to add song as displayed? (y or n): ";
		cin >> userChoice;
		cin.ignore(10, '\n');
		cin.clear();
	
		if ((tolower(userChoice) == 'y'))
		{
			cout << "**********************" << endl;
			cout << "Adding song to the library!" << endl;
			cout << "**********************" << endl;

			if (size == capacity)
			{
				growList();
			}
			mySong.setTitle(titleInput);
			mySong.setArtist(artistInput);
			mySong.setMin(minInput);
			mySong.setSec(secInput);
			mySong.setAlbum(albumInput);

			myList[size].setSong(mySong);

			size++;
		}
		else if ((tolower(userChoice) == 'n'))
		{
			cout << "**********************" << endl;
			cout << "Discarding information" << endl;
			cout << "**********************" << endl;
		}
	}
	while ((tolower(userChoice) != 'y') && (tolower(userChoice) != 'n'));
}
void SongList::growList()
{
	capacity += GROWTH;
	char titleInput[MAX], artistInput[MAX], albumInput[MAX];

	Song *tempList = new Song[capacity];
	
	for (int i = 0; i < size; i++)
	{
		tempList[i].setSong(myList[i]);
	}
	
	delete [] myList;
	myList = tempList;
	tempList = NULL;
}
