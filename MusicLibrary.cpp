//
//  MusicLibrary.cpp
//  asa
//
//  Created by Sevilay Ozturk on 4/3/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#include "MusicLibrary.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

MusicLibrary::MusicLibrary(int maxsongs)
{
   maxSongs = maxsongs;
   numSongs = 0;    // number of Songs in library
   numSongsPlayList = 0; // number of Songs in Playlist
   playList =  new Song*[maxSongs];      // dynamic array of pointers to Songs
   mySongs = new Song [maxSongs];   // dynamic array storing all Songs

}

MusicLibrary::MusicLibrary(MusicLibrary& other)
{
   maxSongs = other.maxSongs;
   numSongs = other.numSongs;    // number of Songs in library
   numSongsPlayList = other.numSongsPlayList; // number of Songs in Playlist
   playList =  new Song*[maxSongs];
   for(int x =0; x < numSongs; x++){
       playList[x] = other.playList[x];
   }
   mySongs = new Song [maxSongs];
   for(int i =0 ; i < numSongs; i++)
        mySongs[i]  = other.mySongs[i];
}

MusicLibrary::~MusicLibrary()
{
    delete[] mySongs;
    delete[] playList;
}

int MusicLibrary::getnumSongs()
{
   return numSongs;
}
int MusicLibrary::getmaxSongs()
{
   return maxSongs;
}
int MusicLibrary::getnumSongsPlayList()
{
   return numSongsPlayList;
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
    if (numSongs == maxSongs) {
        cout << "Could not add song to library. Library is full" << endl;
        return false;
    }
    mySongs[numSongs].setTitle(title);
    mySongs[numSongs].setArtist(artist);
    mySongs[numSongs].setAlbum(album);
    mySongs[numSongs].setYear(year);
    mySongs[numSongs].setPlayTime(time);
    numSongs++;

    return true;
}
bool MusicLibrary::addSong(Song& song)
{
    if (numSongs == maxSongs) {
        cout << "Could not add Ssong to library. Library is full" << endl;
        return false;
    }
    mySongs[numSongs] = song;
    numSongs++;

    return true;
}

void MusicLibrary::readSongsFromFile(string filename)
{

    ifstream input;
    input.open(filename);
    bool cont = true;

    if (input.is_open()) {
        string line;
        while ( getline(input, line) && cont ) {
            string title, artist, album;
            string s_year, s_time;
            int year;
            int time;
            istringstream inSS(line);

            getline(inSS, title, ',');
            getline(inSS, artist, ',');
            getline(inSS, album, ',');
            getline(inSS, s_year, ',');
            getline(inSS, s_time);

            year = stoi(s_year);
            time = stoi(s_time);
            cont = addSong(title, artist, album, year, time);
        };
    }
    else {
       cout << "could not open file " << filename << endl;
    }
}

void MusicLibrary::playRandom()
{
    int i;
    for(i = 0 ; i < numSongs/2 ; i++){
        mySongs[i].Play();
        mySongs[numSongs - (i+1)].Play();
        
    }
    if(numSongs % 2){
        mySongs[i].Play();
    }
}

bool MusicLibrary::addSongToPlayList(int pos){
    if(numSongsPlayList == maxSongs){
        cout << "Could not add Song to PlayList. PlayList is full" << endl;
        return false;
    }
    else if(pos > numSongs || pos < 0){
        cout << "Invalid song" << endl;
        return false;
    }
    else{
        playList[numSongsPlayList] = &mySongs[pos];
        numSongsPlayList += 1 ;
        return true;
    }
}

void MusicLibrary::playPlaylist()
{
    for(int i = 0; i < numSongsPlayList; i++){
        playList[i]-> Play();
    }
}


////implement the public function 'playRandom' which plays all songs of the library ( by invoking the play function of each song) in pseudo-random fashion by alternating songs from the beginning and from the end of the list, until all songs have been played. For example, if the library has 7 songs, the songs will be played in the following order: 0, 6, 1, 5, 2, 4, 3
//implement the public function addSongToPlayList which stores a pointer to a song in the library in the array of Song pointer. The input to this method is an integer denoting the position of the song in the MusicLibrary
//If the Playlist is full, print the following error message
//
//Could not add Song to PlayList. PlayList is full
//If the integer denoting the position of a song in the MusicLibrary is invalid, print the following error message
//
//Invalid song
//implement the public function 'playPlaylist' which plays the songs in the playlist in the same order as the songs have been added to the playlist.
//A sample main file has been provided showing the utilization of the functions, as well as a sample input file.
////
