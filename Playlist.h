#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode {
 public:

	PlaylistNode(string ID = "none", string song = "none", string artist = "none", int slength = 0, PlaylistNode* nextPtr = 0);
    void InsertAfter(PlaylistNode* nodeLoc);
    void SetNext(PlaylistNode*);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    

 private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif
