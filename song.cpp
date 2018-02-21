//Martha Sander - Implementation file for class song.

#include "song.h"

//Song default constructor
Song::Song()
{
	//allocate new char memory to support initialization.
	title = NULL;
	artist = NULL;
	album = NULL;

	min = 0;
	sec = 0;
}
//song constructor with input as parameters
Song::Song(char titleInput[], char artistInput[], int minInput, int secInput, char albumInput[])
{
	title = new char[strlen(titleInput) + 1];
	artist = new char[strlen(artistInput) + 1];
	album = new char[strlen(albumInput) + 1];

	strcpy(title, titleInput);
	strcpy(artist, artistInput);
	min = minInput;
	sec = secInput;
	strcpy(album, albumInput);
}

//copy Constructor
/*Song::Song(const Song &mySong)// REMOVE COPY CONSTRUCTOR OR DO STR COPY
{ 
	title = new char[strlen(mySong.title) + 1];
	artist = new char[strlen(mySong.artist) + 1];
	album = new char[strlen(mySong.album) + 1];

	strcpy(title, mySong.title);
	strcpy(artist, mySong.artist);
	strcpy(album, mySong.album);
	
	min = mySong.min;
	sec = mySong.sec;
}*/
//Song destructor.
Song::~Song()
{
	if(title)
	{
		delete [] title;
		title = NULL;
	}
	if (artist)
	{
		delete [] artist;
		artist = NULL;
	}
	if(album)
	{
		delete [] album;
		album = NULL;
	}
}	
//function setSong.
void Song::setSong(const Song &mySong)
{ 
	if (title)
	{
		delete [] title;
	}
	title = new char[strlen(mySong.title) + 1];
	strcpy(title, mySong.title);
	
	if (artist)
	{
		delete [] artist;
	}
	artist = new char[strlen(mySong.artist) + 1];
	strcpy(artist, mySong.artist);

	if (album)
	{
		delete [] album;
	}
	album = new char[strlen(mySong.album) + 1];
	strcpy(album, mySong.album);

	min = mySong.min;
	sec = mySong.sec;
}
//setTitle implementation.
void Song::setTitle(char titleInput[])
{
	if(title)
	{
		delete [] title;
		title = NULL;
	}
	title = new char[strlen(titleInput) + 1];
	strcpy(title, titleInput);
}	

//setArtist.
void Song::setArtist(char artistInput[])
{
	if(artist)
	{
		delete [] artist;
		artist = NULL;
	}
	artist = new char[strlen(artistInput) + 1];
	strcpy(artist, artistInput);
}

//setMin.
void Song::setMin(int minInput)
{
	min = minInput;
}
//setSec.
void Song::setSec(int secInput)
{	
	sec = secInput;
}

//setalbum.
void Song::setAlbum(char albumInput[])
{
	if(album)
	{
		delete [] album;
		album = NULL;
	}
	album = new char[strlen(albumInput) + 1];
	strcpy(album, albumInput);
}

//accessor functions - don't alter song values.
void Song::getTitle(char returnTitle[]) const
{
	strcpy(returnTitle, title);
}
void Song::getArtist(char returnArtist[]) const
{
	strcpy(returnArtist, artist);
}
int Song::getMin() const
{
	return min;
}
int Song::getSec() const
{
	return sec;
}
void Song::getAlbum(char returnAlbum[]) const
{
	strcpy(returnAlbum, album);
}
//printSong.
void Song::printSong()
{
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Duration: " << min << ":" << sec << endl;
	cout << "Album: " << album << endl;  
} 
