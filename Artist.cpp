//
// Created by meshu on 29/04/2020.
//

#include "Artist.h"
#include "Song.h"
#include "diesesystem.h"
#include "streamNode.h"
#include "assert.h"
#include "string"


Artist::Artist(int artist_id, int numOfSongs, ListNode& node0):artistId(artist_id),songNum(numOfSongs),
        songTree(numOfSongs,Generate(node0)){
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
        songList[i]->listNode.element.removeElement(artistId);
        if(songList[i]->listNode.element.getTreeSize()==0){
            GreatestHitList::removeGHNode(&(songList[i]->listNode));
        }
        delete songList;
    }
}

Artist *Artist::clone() {
    try{
        Artist* temp = new Artist(artistId,songNum,songList[0]->listNode);
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
    if(songId >= songNum || songId < 0) throw INVALID_INPUT();
    Song* newlyAddedSong = nullptr;
    try {
        ListNode &currentNode = songList[songId]->listNode;
        ListNode &nextNode = advance(currentNode);
        Song songNodeToAdd(songId, nextNode);
        newlyAddedSong = songTree.insert(songNodeToAdd);
        assert(currentNode.key == nextNode.key + 1);
        StreamNode tempSNode(this, 1);
        try {
            StreamNode &nodeToAdjust = nextNode.element.findElement(tempSNode);
            nodeToAdjust.songNum++;
        }
        catch (std::exception &e) {
            std::string s = e.what();
            if (s == "Failure") {
                nextNode.element.insert(tempSNode);
            }
        }
        StreamNode &SNode = currentNode.element.findElement(tempSNode);
        if (SNode.songNum == 1) {
            currentNode.element.removeElement(SNode);
            if (currentNode.element.isEmpty()) {
                GreatestHitList::removeGHNode(&currentNode);
            }
        } else {
            SNode.songNum--;
        }
        songTree.removeElement(songList[songId]);
        songList[songId] = newlyAddedSong;
    }
    catch(...){
        if(newlyAddedSong!=nullptr) {
            songTree.removeElement(newlyAddedSong);
        }
        throw;
    }
}

void Artist::resetList() {
    for(int i=0; i<songNum;i++){
        songList[i]= nullptr;
    }

}

int Artist::getStreamNum(int songId) {
    return songList[songId]->listNode.key;

}

int Artist::getSongNum() {
    return songNum;
}

int Artist::hitListIterator(int streamNum){
    Song& s = songTree.getMin();
    if(s.listNode.key == streamNum){
        Song& requested = songTree.startInorder();
        return requested.id;
    }
    Song& requested = songTree.inorderGetNext();
    return requested.id;
}




