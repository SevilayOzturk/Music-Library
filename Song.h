//
//  Song.hpp
//  asa
//
//  Created by Sevilay Ozturk on 4/3/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#ifndef Song_h
#define Song_h

#include <stdio.h>
#pragma once

#include <string>
using namespace std;

class Song {
private:
    string Title;
    string Artist;
    string Album;
    int Year;
    int PlayTime;

public:
    Song();
    Song(string title, string artist, string album, int year, int playtime);
    string getTitle();
    void setTitle(string title);
    string getArtist();
    void setArtist(string artist);
    string getAlbum();
    void setAlbum(string album);
    int getYear();
    void setYear(int year);
    int getPlayTime();
    void setPlayTime(int playtime);
    void Play();
    bool operator == (Song &track);
    
};
#endif /* Song_hpp */
