//
//  Song.cpp
//  asa
//
//  Created by Sevilay Ozturk on 4/3/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#include "Song.h"
#include <iostream>
Song::Song(){
    PlayTime = 0;
    Year = 0;
    Title = "";
    Artist = "";
    Album = "";
}

Song::Song(string title, string artist, string album, int year, int playtime){
       PlayTime = playtime;
       Year = year;
       Title = title;
       Artist = artist;
       Album = album;
}

string Song::getTitle(){
    return Title;
}

void Song::setTitle(string title){
    Title = title;
}

string Song::getArtist(){
    return Artist;
}

void Song::setArtist(string artist){
    Artist = artist;
}

string Song::getAlbum(){
    return Album;
}

void Song::setAlbum(string album){
    Album = album;
}

int Song::getYear(){
    return Year;
}

void Song::setYear(int year){
    Year = year;
}

int Song::getPlayTime(){
    return PlayTime;
}

void Song::setPlayTime(int playtime){
    PlayTime = playtime;
}


bool Song::operator == (Song &track){
    if(Title == track.Title && Artist == track.Artist && Album == track.Album){
        return true;
    }
    return false;
}

void Song::Play()
{
    cout << "Playing "<< Title << " by " << Artist << " " << PlayTime << " seconds" << endl;
}

// Add code for constructors, accessors, mutators, and == operator.
