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
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        if(what == "Invalid Input") return INVALID_INPUT;
        if(what == "Out Of Memory") return ALLOCATION_ERROR;
        }
}

StatusType RemoveArtist(void *DS, int artistID){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        sys->ArtistTree.removeElement(artistID);
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what = e.what();
        if(what == "Fail") return FAILURE;
        if(what == "Out Of Memory") return ALLOCATION_ERROR;
    }

}

StatusType AddToSongCount(void *DS, int artistID, int songID){
    Artist searchA(artistID);
    Artist& a = ArtistTree.findElement(searchA);
}

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);

void Quit(void** DS){

}
/****************************************************************************/
/*                                                                          */
/* File Name : DSI implementation                                           */
/*                                                                          */
/****************************************************************************/

void DSI::addArtist(int artistID, int numOfSongs){
    Artist tempArtist(artistID, numOfSongs, GHList.getmin());
    ArtistTree.addElement(tempArtist);
}
//
// Created by meshu on 29/04/2020.
//
