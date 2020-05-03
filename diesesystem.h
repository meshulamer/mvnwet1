//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_DIESESYSTEM_H
#define WET2_DIESESYSTEM_H

#include "greatestHits.h"
#include "Artist.h"
#include "library1.h"
#include "DSAVLTree.h"

typedef DSAVLTree<Artist,artistCompare> ArtistTree;
typedef greatestHits<DSAVLTree<Artist*,artistPtrCompare>> GreatestHitList;
class DSI{
public:
    ArtistTree ArtistTree;
    GreatestHitList GHList;
    void addArtist(int artistID, int numOfSongs);

};


#endif //WET2_DIESESYSTEM_H
