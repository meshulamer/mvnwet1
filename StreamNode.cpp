//
// Created by meshu on 03/05/2020.
//

#include "StreamNode.h"
StreamNode* StreamNode::clone(){
return new StreamNode(artist,songNum);
}

StreamNode::StreamNode(Artist* artist,int songNum = 0):artist(artist),songNum(songNum){}


int compareStreamNode::operator()(const StreamNode &s1, const StreamNode &s2) {
    return s1.artist->getId()-s2.artist->getId();
}
