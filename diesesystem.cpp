//
// Created by meshu on 29/04/2020.
//

#include "diesesystem.h"
#include "library1.h"

/*                                                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/* File Name : dieselsystem implementation                                  */
/*                                                                          */
/****************************************************************************/

void *Init(){
}

StatusType AddArtist(void *DS, int artistID, int numOfSongs){
    if(!DS||artistID <=0 || numOfSongs <=0) return INVALID_INPUT;
    try {
        DSI *sys = static_cast<DSI *>(DS);
        (*sys).addArtist(artistID, numOfSongs);
    }
    catch(std::exception&) {
        return INVALID_INPUT;
    }
    return SUCCESS;
}

StatusType RemoveArtist(void *DS, int artistID);

StatusType AddToSongCount(void *DS, int artistID, int songID);

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);

/****************************************************************************/
/*                                                                          */
/* File Name : DSI implementation                                           */
/*                                                                          */
/****************************************************************************/

void DSI::addArtist(int artistID, int numOfSongs){
    Artist tempArtist(artistID,numOfSongs);
    ArtistTree.addElement(artistID,0,gh.n0());
    gh.addToN0(artistID,numOfSongs);
}
//
// Created by meshu on 29/04/2020.
//
