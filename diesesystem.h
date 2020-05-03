//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_DIESESYSTEM_H
#define WET2_DIESESYSTEM_H

#include "greatestHits.h"
#include "Artist.h"
#include "library1.h"
#include "DSAVLTree.h"

typedef DSAVLTree<int,int,Artist,,> ArtistTree;
class DSI{
private:
    ArtistTree ArtistTree;
    greatestHits gh;
public:
    void addArtist(int artistID, int numOfSongs);

}


#endif //WET2_DIESESYSTEM_H
