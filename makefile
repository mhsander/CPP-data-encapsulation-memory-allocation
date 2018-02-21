all:
	g++ -g -o proj4 song.cpp song.h songList.cpp songList.h main.cpp

clean:
	rm proj4
