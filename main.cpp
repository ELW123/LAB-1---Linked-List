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

void printMenu(PlaylistNode& playlist, string name) {
	// variables here to show user input and all other necessary changes (to be filled in further)
	string userInput;
	string playlistUniqueID;
	string playlistName;
	string playlistArtistName;
	string playlistSongLength;
	
	string removedID;

	printMenuChoices(name);

	while (1) {
		userInput.clear();
    	cout << "Choose an option: " << endl;
    	cin >> userInput;

    	if (userInput == "q") break;

		if (userInput != "a" && userInput != "d" && userInput != "c" && userInput != "i" && userInput != "o") continue;
        
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

			// create new playlistNode and use insertAfter function
			
			printMenuChoices();
			continue;
		}

		// need to implement how to remove
		if (userInput == "d") {
			cout << "REMOVE SONG" << endl 
                 << "Enter song's unique ID: " << endl;
			
			cin.clear();
            cin.ignore(1);
            getline(std::cin, removedID);

			printMenuChoices();
			continue;
		}

		// need to implement printing the other nodes and situation where playlist is empty
		if (userInput == "o") {
			cout << endl << name << "- OUTPUT FULL PLAYLIST" << endl;
			playlist.PrintPlaylistNode();

			printMenuChoices();
			continue;
		}
	}
}

int main() {
	
	string title;
	cout << "Enter playlist's title:" << endl;
	cin >> title;
	cout << title;

    return 0;
}
