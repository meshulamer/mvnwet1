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


class Artist {

public:
    Artist(int artist_id, int numOfSongs);
    Artist(const Artist& artist) = default;
    ~Artist(){}
    Artist& operator = (const Artist& artist) = delete;
    int getId() const{
        return artistId;
    }
class INVALID_INPUT : public std::exception{};

private:
    int artistId;
    int songNum;
    Song* SongList;
};


class artistCompare{
    int operator()(const Artist& a,const Artist& b){
        return a.getId() - b.getId();
    }
};

typedef DSAVLTree<Artist&, artistCompare> StreamTree;




#endif //WET2_ARTIST_H
