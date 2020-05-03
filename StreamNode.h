//
// Created by meshu on 03/05/2020.
//

#ifndef WET2_STREAMNODE_H
#define WET2_STREAMNODE_H

#include "Artist.h"

class StreamNode {
public:
    Artist& artist;
    int songNum;
    explicit StreamNode(Artist& artist,int songNum);
    StreamNode* clone();
};


#endif //WET2_STREAMNODE_H
