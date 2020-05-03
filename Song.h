//
// Created by meshu on 03/05/2020.
//

#ifndef WET2_SONG_H
#define WET2_SONG_H
#include "Artist.h"



class Song {
public:
    int id;
    streamNode ListNode;
};

Class compareSong{
    int operator()(const Song& s1, const Song& s2){
        int first_comp = s1.streamNode->key - s2.streamNode.key;
        if (first_comp = 0) {
            return s1.id - s2.id;
        }
        return first_comp;
        }
    }
};



#endif //WET2_SONG_H
