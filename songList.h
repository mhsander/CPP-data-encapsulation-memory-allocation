//Martha Sander - SongList class definition to contain library of songs.

#include "song.h"

#ifndef SONG_LIST
#define SONG_LIST

const int CAP = 10;
const int GROWTH = 5;

class SongList
{
public:
	//default constructor to initialize size to 0.
	SongList();
	//constructor to extract information from file with library information. Load list of songs to the library.
	SongList(char fileName[]);
	//SongList destructor.
	~SongList();
	//function to add song at size to songList variable.
	void addSong(const Song &mySong);
	//function to add song as inputed by user.
	void addInput(Song &mySong);
	//function to access list size. Return size.
	int getSize();
	//functions to search all music by artist name or by album name.
	void searchByArtist(char returnArtist[]);
	void searchByAlbum(char returnAlbum[]);
	void printAllSongs();
	//function to remove song by index.
	void removeSong();
	//function to safe song library to file.
	void saveFile(char fileName[], char returnTitle[], char returnArtist[], char returnAlbum[]);

private:

	int size;
	Song *myList;
	int capacity;
	void growList();
};

#endif
