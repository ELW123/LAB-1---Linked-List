#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode {
 public:
    PlaylistNode();
	PlaylistNode(string ID, string song, string artist, int slength);
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

class Playlist {
 public:
    Playlist();
    void AddSong(string ID, string songName, string artistName, int length);
    void RemoveSong(string id);
    void PrintList();
    void ChangePosition(int posO, int posN);
    //void SongsByArtist(string artist);
    //int TotalTime();

 private:
   PlaylistNode *head;
   PlaylistNode *next;
};

#endif
