//
// Created by meshu on 29/04/2020.
//

#include "Artist.h"
#include "Song.h"
#include "diesesystem.h"

typedef greatestHits<StreamTree>::GHNode streamNode;
Artist::Artist(int artist_id, int numOfSongs, ListNode *node0):artistId(artist_id),songNum(numOfSongs),
        songTree(numOfSongs, node0) {
    if (artist_id <= 0 || numOfSongs <= 0) throw INVALID_INPUT();
    artistId = artist_id;
    songNum = numOfSongs;
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
        if (songList[i]==nullptr) continue;
        songList[i]->ListNode.element.removeElement(artistId);
        if(songList[i]->ListNode.element.getTreeSize()==0){
            removeGHNode(songList[i]->ListNode);
        }
        delete songList;
    }
}

Artist *Artist::clone() {
    try{
        Artist* temp = new Artist(artistId,songNum,songList[0]->ListNode);
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

void Artist::addSongCount(int songId) {
    Song& song = songList[songId]->ListNode;
    if(songId >= songNum || songId < 0) throw INVALID_INPUT();
    try {
        streamNode& current_Node = advance(song.ListNode);
        streamNode& find = song.ListNode.element.findElement(artistId);

    }
    catch(...){
        throw OUT_OF_MEM();
    }
    assert(song.ListNode.key == song.ListNode.key +1);
}




