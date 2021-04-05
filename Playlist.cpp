/* 	Collaborated with: 
	Ethan Wan, 
	Ethan Wan's prior HW assignments in CS 10B, 
	Mariam Golwalla, 
	Yugarshi Shashwat, 
	zybooks.com - CS 10C and CS 10B, 
	github.com to host our code
*/

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
	// add two empty elements as sentinels head to make things easier
	head = new PlaylistNode();
	head->SetNext(nullptr);
	tail = head;
}

// destructor
Playlist::~Playlist() {
        PlaylistNode* iter = head;

        while (iter != nullptr) {
                PlaylistNode* tmp = iter;
                iter = iter->GetNext();
                delete tmp;
        }
}

void Playlist::AddSong(string idP, string songNameP, string artistNameP, int lengthP) {
	PlaylistNode* addition = new PlaylistNode(idP, songNameP, artistNameP, lengthP);
	
	tail->SetNext(addition);
	tail = addition;
}

void Playlist::RemoveSong(string idP) {
	PlaylistNode* prev = head;
	PlaylistNode* curr = prev->GetNext();
   	while (curr != nullptr) {
       if (curr->GetID() == idP)       
           break;

       prev = curr;
       curr = curr->GetNext();
   	}
	
    if (curr != nullptr) {
        prev->SetNext(curr->GetNext());
	delete curr;
	cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl << endl;
    }
}

void Playlist::ChangePosition(int posO, int posN) {
	// basic checks
	if (head == nullptr) return;
	if (posO == posN) return;
	if (posO < 1) {
		cout << "invalid old position."; // not in zybooks test harness - personal use
		return;
	}

	// find the old position
	PlaylistNode* preCurrOld = head;
	int index = 0;
	while (preCurrOld != nullptr) {
		index++;

		if (index == posO) 
			break; //found	

		preCurrOld = preCurrOld->GetNext();
	}

	if (index != posO) {
		cout << "invalid old position.";
		return;
	}
	// now perCurrOld is pointing to the element just before the old position
	
	if (posN <= 1) { // move curr to the head
		PlaylistNode* curr = preCurrOld->GetNext();
		preCurrOld->SetNext(curr->GetNext());
		// update next if necessary

		if (preCurrOld->GetNext() == nullptr) 
			tail =preCurrOld;

		curr->SetNext(head->GetNext());
		head->SetNext(curr);
		return;
	}

	// find the new position
	if (posO <= posN) 
		++posN;

	PlaylistNode* preCurrNew = head;
	index = 0;
	
	while (preCurrNew != nullptr) {
		index++;

		if (index == posN) 
			break; //found	
		preCurrNew = preCurrNew->GetNext();
	}	
	if (index != posN) { // move curr to the end of the list
		PlaylistNode* curr = preCurrOld->GetNext();
		preCurrOld->SetNext(curr->GetNext());
		curr->SetNext(nullptr);
		tail->SetNext(curr);
		tail=curr;
		return;
	}
	// now move to the new position
	{
		PlaylistNode* curr = preCurrOld->GetNext();
		preCurrOld->SetNext(curr->GetNext());
		// update next if necessary
		
		if (preCurrOld->GetNext() == nullptr) 
			tail=preCurrOld;
		
		curr->SetNext(preCurrNew->GetNext());
		preCurrNew->SetNext(curr);

		cout << "\"" << curr->GetSongName() << "\"" << " moved to position " << posN - 1 << endl << endl;

		return;
	}
}

void Playlist::PrintList() {
	PlaylistNode* display = head->GetNext();
	int i = 1;

	if (display == nullptr) {
		cout << "Playlist is empty" << endl << endl;
		return;
	}
	
	for (i = 1; display != nullptr; display = display->GetNext()) {
		cout << i++ << "." << endl;
		display->PrintPlaylistNode();
	}
}

void Playlist::SongsByArtist(string artist){
 	int x = 1;
	PlaylistNode* c = head;
			while (c != 0) {
				if (c->GetArtistName() == artist) {
      				cout << x << "." << endl;
					c->PrintPlaylistNode();
					x++;
				}
      			c = c->GetNext();
   			}
} 

int Playlist::TotalTime() {
	int total = 0;
	PlaylistNode* currentN = head;
		while(currentN != 0){
			total = total + currentN->GetSongLength();
			currentN = currentN->GetNext();
	}
	return total; 
}
