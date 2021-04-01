#include "Playlist.h"

#include <iostream>
using namespace std;

void printMenuChoices(string name) {
    cout << name << " PLAYLIST MENU" << endl
      << "a - Add song" << endl
      << "d - Remove song" << endl
      << "c - Change position of song" << endl
      << "s - Output songs by specific artist" << endl
      << "t - Output total time of playlist (in seconds)" << endl
	  << "o - Output full playlist" << endl
      << "q - Quit" << endl
      << endl;
}

void printMenu(string name) {
	// variables here to show user input and all other necessary changes (to be filled in further)
	string userInput;
	string playlistUniqueID;
	string playlistName;
	string playlistArtistName;
	int playlistSongLength;
	int positionOld;
	int positionNew;
	string removedID;

	PlaylistNode* playlist = new PlaylistNode;
	playlist = nullptr;

	printMenuChoices(name);

	while (1) {
		userInput.clear();
    	cout << "Choose an option:" << endl;
    	cin >> userInput;

    	if (userInput == "q") break;

		if (userInput != "a" && userInput != "d" && userInput != "c" && userInput != "i" && userInput != "o") {
			continue;
		}
        
		if (userInput == "a") {
			cout << endl << "ADD SONG" << endl
				 << "Enter song's unique ID: " << endl;
			cin.clear();
        	cin.ignore(1);
        	getline(std::cin, playlistUniqueID);
			cout << playlistUniqueID << endl;

			cout << "Enter song's name: " << endl;
			getline(std::cin, playlistName);
			cout << playlistName << endl;

			cout << "Enter artist's name: " << endl;
			getline(std::cin, playlistArtistName);
			cout << playlistArtistName << endl;

			cout << "Enter song's length (in seconds) : " << endl;
			cin >> playlistSongLength;
			cout << playlistSongLength << endl;

			// double check here!
			PlaylistNode* addition = new PlaylistNode(playlistUniqueID, playlistName, playlistArtistName, playlistSongLength);
			playlist->InsertAfter(addition);
			printMenuChoices(name);
			continue;
		}

		// need to implement how to remove
		if (userInput == "d") {
			cout << "REMOVE SONG" << endl 
                 << "Enter song's unique ID: " << endl;
			
			cin.clear();
            cin.ignore(1);
            getline(std::cin, removedID);

			printMenuChoices(name);
			continue;
		}

		if (userInput == "c") {
			cout << "CHANGE POSITION OF SONG" << endl 
                 << "Enter song's current position: " << endl;

			cin.clear();
            cin.ignore(1);
			cin >> positionOld;
			cout << positionOld << endl;

			cout << "Enter new position for song: " << endl;
			cin >> positionNew;
			cout << positionNew << endl;

			// do some change position stuff here later
		}

		if (userInput == "s") {
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl 
                 << "Enter artist's name: " << endl;

			cin.clear();
            cin.ignore(1);
			getline(std::cin, playlistArtistName);
			cout << playlistArtistName;

			PlaylistNode* currObj = playlist;
			while (currObj != nullptr) {
				if (currObj->GetArtistName() == playlistArtistName)
      				currObj->PrintPlaylistNode();

      			currObj = currObj->GetNext();
   			}
			
			printMenuChoices(name);
			continue;
		}

		// need to implement printing the other nodes and situation where playlist is empty
		if (userInput == "o") {
			cout << endl << name << "- OUTPUT FULL PLAYLIST" << endl;
			
			if (playlist != nullptr) 
				playlist->PrintPlaylistNode();
			else
				cout << "Playlist is empty" << endl << endl;

			printMenuChoices(name);
			continue;
		}
	}
}

int main() {
	
	string title;
	cout << "Enter playlist's title:" << endl << endl;
	cin.clear();
	getline(std::cin, title);

	printMenu(title);
    return 0;
}
