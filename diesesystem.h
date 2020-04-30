//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_DIESESYSTEM_H
#define WET2_DIESESYSTEM_H

#include "greatestHits.h"
#include "Artist.h"

typedef DSAVLTree<int,int,Artist> ArtistTree;
class DS{
private:
    ArtistTree ArtistTree;
    greatestHits gh;
}


#endif //WET2_DIESESYSTEM_H
