//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_GREATESTHITS_H
#define WET2_GREATESTHITS_H
#include <stdlib.h>
#include <stdio.h>
#include <bits/exception.h>
#include <string.h>

typedef DSAVLTree<Artist*,int,int> ArtistStreamTree;
class GHNode{
public:
    int streamsnum;
    ArtistStreamTree;
    GHNode*  Next;
    GHNode* Last;
};

class greatestHits {
public:

private:
    GHNode* min;
    GHNode* max;

};


#endif //WET2_GREATESTHITS_H
