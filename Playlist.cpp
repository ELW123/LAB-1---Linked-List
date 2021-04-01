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



void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
   PlaylistNode* tmpNext = nullptr;
   tmpNext = this->nextNodePtr;    
   this->nextNodePtr = nodeLoc;    
   nodeLoc->nextNodePtr = tmpNext; 
}

void PlaylistNode:: PrintPlaylistNode() {
	cout << "Unique ID: " << this->uniqueID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artist Name: " << this->artistName << endl;
	cout << "Song Length (in seconds): " << this->songLength << endl; 
}

void PlaylistNode::SetNext(PlaylistNode* set) {
   this->nextNodePtr = set;
}

// accessors
PlaylistNode* PlaylistNode::GetNext() {
   return this->nextNodePtr;
}

string PlaylistNode::GetID() const{
   return uniqueID;
}

string PlaylistNode::GetSongName() const{
   return songName;
}

string PlaylistNode::GetArtistName() const{
   return artistName;
}

int PlaylistNode::GetSongLength() const{
   return songLength;
}
    
