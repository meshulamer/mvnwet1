//
// Created by meshu on 29/04/2020.
//

#include "diesesystem.h"
#include "library1.h"
#include <string>

/*                                                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/* File Name : dieselsystem implementation                                  */
/*                                                                          */
/****************************************************************************/

void *Init(){
    try{
        DSI* DS = new DSI();
        return DS;
    }
    catch(...){
        return nullptr;
    }
}

StatusType AddArtist(void *DS, int artistID, int numOfSongs){
    if(!DS||artistID <=0 || numOfSongs <=0) return INVALID_INPUT;
    try {
        DSI *sys = static_cast<DSI *>(DS);
        (*sys).addArtist(artistID, numOfSongs);
        sys->totalNumOfSongs += numOfSongs;
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
        }
}

StatusType RemoveArtist(void *DS, int artistID){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        Artist dummyArtist(artistID);
        Artist& artist = sys->ArtistTree.findElement(dummyArtist);
        int numOfArtistSongs = artist.getSongNum();
        sys->ArtistTree.removeElement(dummyArtist);
        sys->totalNumOfSongs -= numOfArtistSongs;
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }

}

StatusType AddToSongCount(void *DS, int artistID, int songID){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        Artist dummyArtist(artistID);
        Artist& artist = sys->ArtistTree.findElement(dummyArtist);
        artist.addSongCount(songID);
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }

}

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        Artist dummyArtist(artistID);
        Artist& artist = sys->ArtistTree.findElement(dummyArtist);
        artist.getStreamNum(songID);
        return SUCCESS;

    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }
}

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        ListNode& node = sys->GHList.getMax();
        if(sys->totalNumOfSongs<numOfSongs) return FAILURE;
        Recommended(numOfSongs,artists, songs);
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }
}

void Quit(void** DS){
    try {
        DSI *sys = static_cast<DSI *>(*DS);
        delete sys;
        *DS = nullptr;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }

}
/****************************************************************************/
/*                                                                          */
/* File Name : DSI implementation                                           */
/*                                                                          */
/****************************************************************************/
#include<string>

StatusType handelError(const std::string& what){
    if(what == "Invalid Input") return INVALID_INPUT;
    if(what == "Out Of Memory") return ALLOCATION_ERROR;
    if(what == "Failure") return FAILURE;
}

void DSI::addArtist(int artistID, int numOfSongs){
    Artist tempArtist(artistID, numOfSongs, GHList.getMin());
    ArtistTree.insert(tempArtist);
    tempArtist.resetList();
}
void Recommended(GreatestHitList& HL, int numOfSongs, int*artists, int*songs){
    ListNode* start = &HL.getMax();
    int i =0;
    int j = 0;
    while(start){
        StreamNode* streamIterator = start->element.startInorder();
        while(streamIterator){
            Artist* artist = streamIterator->artist;
            int songCounter = streamIterator->songNum;
            for (int t=0; t<songCounter; t++){
                artists[i]= artist->getId();
                i++;
            }
            for(int t=0; t<songCounter; t++){
                songs[j] = artist->hitListIterator(start->key);
                j++;
            }
            streamIterator = start->element.inorderGetNext();
        }
        start = start->prev;
    }
}
//
// Created by meshu on 29/04/2020.
//
