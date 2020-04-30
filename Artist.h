//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_ARTIST_H
#define WET2_ARTIST_H
#include <stdlib.h>
#include <stdio.h>
#include <bits/exception.h>
#include <string.h>

typedef DSAVLTree<GHNode*, int, void> songTree;
class Artist {
private:
    int artistId;
    int numofsongs;
    Song* Array;
    songtree tree;

public:
    Artist(int artist_id, int numOfSongs);
    Artist(Const Artist& artist) = default;
    ~Artist(){}
    Artist& operator = (Const Artist& artist) = delete;
    friend int operator <(Const Artist& artistA Const artist& artistB);
class INVALID_INPUT : public std::exception{
    public:
        const char* what() const override {
        return "Invalid Input"
    }
    };

};


#endif //WET2_ARTIST_H
