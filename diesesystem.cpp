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
        handelError(what);
        }
}

StatusType RemoveArtist(void *DS, int artistID){
    try {
        DSI *sys = static_cast<DSI *>(DS);
        sys->ArtistTree.removeElement(artistID);
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
        Artist& a = sys->ArtistTree.findElement(dummyArtist);
        a.addSongCount(songID);
        return SUCCESS;
    }
    catch(std::exception& e) {
        std::string what =e.what();
        handelError(what);
    }

}

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams){}

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);

void Quit(void** DS){

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
}
//
// Created by meshu on 29/04/2020.
//
