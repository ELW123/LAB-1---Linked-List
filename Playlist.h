#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class Playlist {
 public:
    // constructors to be added

    // Public member functions
    /*
    InsertAfter();
    SetNext();
    GetID();
    GetSongName();
    GetArtistName();
    GetSongLength();
    GetNext();
    string PrintPlaylistNode();
    */

 private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    //PlaylistNode* nextNodePtr;
};

#endif