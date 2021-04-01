#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode {
 public:

	PlaylistNode( string ID = "none", string song = "none", string artist = "none", int slength = 0, PlaylistNode* nextPtr = 0);
    InsertAfter();
    SetNext();
    GetID();
    GetSongName();
    GetArtistName();
    GetSongLength();
    GetNext();
    PrintPlaylistNode();
    

 private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif
