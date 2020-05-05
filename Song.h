//
// Created by meshu on 03/05/2020.
//

#ifndef WET2_SONG_H
#define WET2_SONG_H
#include "Artist.h"
#include "diesesystem.h"



class Song {
public:
    int id;
    ListNode& listNode;
    Song(int id, ListNode& listNode);
    Song* clone();
};

Class compareSong{
    int operator()(const Song& s1, const Song& s2);
};

class Generate{
public:
    Song* operator()(int m);
    Generate(ListNode& node);
private:
    ListNode& listNode;
};


#endif //WET2_SONG_H
