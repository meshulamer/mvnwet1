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
typedef DSAVLTree<Song,compareSong> SongTree;
typedef DSAVLTree<StreamNode,compareStreamNode> StreamTree;
typedef greatestHits<StreamTree> GreatestHitList;
typedef greatestHits<StreamTree>::GHNode ListNode;

class DSI{
public:
    ArtistTree ArtistTree;
    GreatestHitList GHList;
    void addArtist(int artistID, int numOfSongs);

};
StatusType handelError(const std::string& what);

#endif //WET2_DIESESYSTEM_H
