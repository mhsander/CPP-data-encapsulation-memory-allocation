//Martha Sander -  main function to call functions.


#include "song.h"
#include "songList.h"

//function to display menu options and execute them.
void displayMenu(SongList &myLibrary);

int main()
{
	char fileName[20] = "songs.txt";
	//SongList myLibrary;
	SongList myLibrary(fileName);

	displayMenu(myLibrary);

	return 0;
}

void displayMenu(SongList &myLibrary)
{
	char returnTitle[MAX], returnArtist[MAX], returnAlbum[MAX];
	char userChoice;
	int size = 0;
	char fileName[20] = "songs.txt";
	Song mySong;

	cout << "*****Welcome to your songs library*****" << endl;
	do
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "S: " << "Show all songs and index" << endl;
		cout << "T: " << "Show songs by artist" << endl;
		cout << "B: " << "Show songs by album" << endl;
		cout << "R: " << "Remove songs by index" << endl;
		cout << "A: " << "Add new songs to library" << endl;
		cout << "V: " << "Save library" << endl;
		cout << "Q: " << "Save library and quit program" << endl;
		cin >> userChoice;
		cin.ignore(MAX, '\n');
		
		switch (toupper(userChoice))
		{
			case 'S':
				size = myLibrary.getSize();
				if (size == 0)
				{
					cout << "Library is empty! How about adding some songs?" << endl << endl;
					break;
				}
				myLibrary.printAllSongs();
				break;
			case 'T':
				myLibrary.searchByArtist(returnArtist);
				break;
			case 'B':
				myLibrary.searchByAlbum(returnAlbum);
				break;
			case 'R':
				myLibrary.removeSong();
				break;
			case 'A':
				myLibrary.addInput(mySong);
				break;
			case 'V':
				myLibrary.saveFile(fileName, returnTitle, returnArtist, returnAlbum);
				break;
			case 'Q':
				myLibrary.saveFile(fileName, returnTitle, returnArtist, returnAlbum);
				break;
			default:
				cin.clear();
				cout << "Oooops, option unaveilable! Please try again" << endl << endl;
				break;
		}
	}
	while ((toupper(userChoice)) != 'Q');
	cout << "**Closing your songs library**" << endl;
}
