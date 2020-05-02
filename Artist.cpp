//
// Created by meshu on 29/04/2020.
//

#include "Artist.h"
Artist::Artist(int artist_id, int numOfSongs) {
    if (artist_id <= 0 || numOfSongs <= 0) throw INVALID_INPUT();
    artistId = artist_id;
    this->numOfSongs = numOfSongs;
    songList = SongList(artist_id,numOfSongs); //whoever tries to create this needs to try and catch
    //comment
}



