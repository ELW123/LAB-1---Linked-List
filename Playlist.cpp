#include <iostream>

using namespace std;

#include "Playlist.h"

// playlistnode stuff
PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int slength){
	this->uniqueID = ID;
	this->songName = song;
	this->artistName = artist;
	this->songLength = slength;
	this->nextNodePtr = nullptr; 
	
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
	cout << "Song Length (in seconds): " << this->songLength << endl << endl; 
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

// playlist class stuff
Playlist::Playlist() {
	head = nullptr;
	next = nullptr;
}

void Playlist::AddSong(string idP, string songNameP, string artistNameP, int lengthP) {
	PlaylistNode* addition = new PlaylistNode(idP, songNameP, artistNameP, lengthP);
	
	if (head == nullptr) {
		head = addition;
		next = addition;
	} else { // this part is the main problematic part! It should be fixed for now
		next->InsertAfter(addition);
		next = addition;
	}

	/*
	if (head == nullptr)
		head = addition;

	else if (head != nullptr && next == nullptr)
		next = addition;
	else
		next->InsertAfter(addition);
		*/
}

void Playlist::RemoveSong(string idP) {
	if (head == nullptr) {
		cout << "Playlist is empty" << endl;
		return;
	}

	PlaylistNode* curr = head;
	PlaylistNode* prev = nullptr;
   	while (curr != nullptr) {
       if (curr->GetID() == idP)       
           break;

       prev = curr;
       curr = curr->GetNext();
   	}
	
    if (prev != nullptr)
        prev->SetNext(curr->GetNext());
	else
        head = curr->GetNext();

    if (next == curr)
           next = prev;
    
	cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl << endl;
    delete curr;
}

void Playlist::ChangePosition(int posO, int posN) {

}

void Playlist::PrintList() {
	PlaylistNode* display = head;
	int i = 1;

	if (head == nullptr) {
		cout << "Playlist is empty" << endl << endl;
		return;
	}
	
	for (i = 1; display != nullptr; display = display->GetNext()) {
		cout << i++ << "." << endl;
		display->PrintPlaylistNode();
	}
}

// I think (not confirmed) this should be in main.cpp based on some prior experience
/*
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
*/
    
