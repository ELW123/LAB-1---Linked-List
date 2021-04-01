#include <iostream>

using namespace std;

#include "Playlist.h"

PlaylistNode :: PlaylistNode( string ID, string song, string artist, int slength, PlaylistNode* nextPtr){
	this->uniqueID = ID;
	this->songName = song;
	this->artistName = artist;
	this->songLength = slength;
	this->nextNodePtr = nextPtr; 
	
}



void PlaylistNode::InsertAfter(IntNode* nodeLoc) {
   PlaylistNode* tmpNext = nullptr;
   tmpNext = this->nextNodePtr;    
   this->nextNodePtr = nodeLoc;    
   nodeLoc->nextNodePtr = tmpNext; 
}

PlaylistNode* PlaylistNode::GetNext() {
   return this->nextNodePtr;
}

void PlaylistNode:: PrintPlaylistNode() {
	cout << "Unique ID: " << this->uniqueID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artist Name: " << this->artistName << endl;
	cout << "Song Length (in seconds): " << this->songLength << endl; 
}

    SetNext();
    GetID();
    GetSongName();
    GetArtistName();
    GetSongLength();
    
    
