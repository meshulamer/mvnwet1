//
// Created by meshu on 03/05/2020.
//

#ifndef WET2_STREAMNODE_H
#define WET2_STREAMNODE_H

#include "Artist.h"

class StreamNode {
public:
    Artist* artist;
    int songNum;
    StreamNode(Artist* artist, int songNum);
    StreamNode* clone();
};

class compareStreamNode{
    int operator()(const StreamNode& s1,const StreamNode& s2);
};


#endif //WET2_STREAMNODE_H
