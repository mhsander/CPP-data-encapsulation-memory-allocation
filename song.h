//Martha Sander - May 2017 - CS 162 - Project4 - Pointers.
//Sources: GD Iyer Video Store class examples.
//Header files for class Song.

#ifndef SONG
#define SONG

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

const int MAX = 100;
using namespace std;

//define class Song.
class Song
{
public:
	//default constructor to initialize song values.
	Song();
	//constructor passing parameters to song values.
	Song(char titleInput[], char artistInput[], int minInput, int secInput, char albumInput[]);
	//Song destructor to avoid memory leaks.
	~Song();
	//mutator functions to alter song values.
	void setSong(const Song &mySong);
	void setTitle(char titleInput[]);
	void setArtist(char artistInput[]);
	void setMin(int minInput);
	void setSec(int secInput);
	void setAlbum(char album[]);
	//accessor functions - don't alter song values. "Return" song private information with new variables.
	void getTitle(char returnTitle[]) const;
	void getArtist(char returnArtist[]) const;
	int getMin() const;
	int getSec() const;
	void getAlbum(char returnAlbum[]) const;
	//function to set song information according to user input.
	void setSong(char titleInput[], char artistInput[], int& minInput, int& secInput, char albumInput[]);
	//function to print all songs information.
	void printSong();

private:
	//information to each song.
	char* title;;
	char* artist;
	char* album;
	int min;
	int sec;
};

#endif
