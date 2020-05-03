//
// Created by meshu on 29/04/2020.
//

#include "Artist.h"
#include "Song.h"
typedef greatestHits<StreamTree>::GHNode streamNode;
Artist::Artist(int artist_id, int numOfSongs, streamNode *node0) {
    if (artist_id <= 0 || numOfSongs <= 0) throw INVALID_INPUT();
    artistId = artist_id;
    songNum = numOfSongs;
    songTree = songTree(numOfSongs, node0);
    try {
        songList = new Song *[numOfSongs];
        Song *iterator = songTree.startInorder();
        int i = 0;

        while (iterator != nullptr) {
            songList[i] = iterator;
            i++;
            iterator = songTree.nextInorder();
        }
    }
    catch(...){
        throw OUT_OF_MEM();
    }
}

Artist::~Artist() {
    for(int i=0; i<songNum;i++){
        songList[i]->streamNode.element.removeElement(artistId);
        if(songList[i]->streamNode.element.getTreeSize()==0){
            removeGHNode(songList[i]->streamNode);
        }
        delete songList;
    }
}

Artist *Artist::clone() {
    try{
        Artist* temp = new Artist(artistId,songNum,songList[0]->streamNode);
        return temp;
    }
    catch(...){
        return nullptr;
    }

}

Artist::Artist(int artistId) {
    this->artistId = artistId;
    songNum = 0;
    songList = nullptr;
}
/*
void Artist::addSongCount(int songid) {
    Song& song = songList[songid]->streamNode;
    try {
        song.streamNode.advance(song.streamNode);
    }
    catch(...){
        throw OUT_OF_MEM();
    }
    assert(song.streamNode.key == song.streamNode.key +1);
    song.streamNode.
}
*/



