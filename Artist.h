//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_ARTIST_H
#define WET2_ARTIST_H
#include <stdlib.h>
#include <bits/exception.h>
#include "greatestHits.h"
#include "DSAVLTree.h"
#include "Song.h"
#include <stdio.h>
#include "diesesystem.h"

class Artist {

public:
    Artist(int artistId);
    Artist(const Artist& artist) = default;
    Artist(int artist_id, int numOfSongs, ListNode& node0);
    ~Artist();
    Artist& operator = (const Artist& artist) = delete;
    Artist* clone();
    int getId() const{
        return artistId;
    }
    void addSongCount(int songId);
    void resetList();
    int getStreamNum(int songId);
class INVALID_INPUT : public std::exception{
    const char* what() const throw(){
        return "Invalid Input";
    }
};
class OUT_OF_MEM : public std::exception{
    const char* what() const throw(){
        return "Out Of Memory";
    }
};

private:
    int artistId;
    int songNum;
    SongTree songTree;
    Song** songList;

};


class artistCompare{
    int operator()(const Artist& a,const Artist& b){
        return a.getId() - b.getId();
    }
};

class artistPtrCompare{
    int operator()(const Artist* a,const Artist* b){
       return artistCompare(*a,*b);
    }
};
typedef DSAVLTree<Artist&, artistCompare> StreamTree;





#endif //WET2_ARTIST_H
