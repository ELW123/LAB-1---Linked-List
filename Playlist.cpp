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

void PlaylistNode :: PrintMenu(string t){
	
	char c; 
	cout << t << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	cout << "Choose an option:" << endl;
	cin >> c;
	
	while ( c!="a" || c!="d" || c!="c" || c!="s" || c!="t" || c!="o" || c!="q" ){
		cout << "Choose an option:" << endl;
		cin >> c;
	}
	
	if ( c == "q"){
		break;
	}
	while ( c != "q"){
		if ( c == "a")
		AddSong();
		else if ( c == "d")
		RemoveSong();
		else if ( c == "c")
		****
		else if ( c == "s")
		****
		else if (c == "t")
		***
		else if (c == "o")
		****
		
	}
	
}
    
