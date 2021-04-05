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
	int posOld;
	int posNew;
	string removedID;
	int num = 1;
	int totalTime = 0;

	PlaylistNode* playlist = new PlaylistNode();
	playlist = nullptr;
	PlaylistNode* currObj = new PlaylistNode();
	currObj = nullptr;

	Playlist pList;

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
				 << "Enter song's unique ID:" << endl;
			cin.clear();
        	cin.ignore(1);
        	getline(std::cin, playlistUniqueID);

			cout << "Enter song's name:" << endl;
			getline(std::cin, playlistName);

			cout << "Enter artist's name:" << endl;
			getline(std::cin, playlistArtistName);

			cout << "Enter song's length (in seconds):" << endl << endl;
			cin >> playlistSongLength;

			pList.AddSong(playlistUniqueID, playlistName, playlistArtistName, playlistSongLength);

			printMenuChoices(name);
			continue;
		}

		if (userInput == "d") {
			cout << "REMOVE SONG" << endl 
                 << "Enter song's unique ID:" << endl;
			
			cin.clear();
            cin.ignore(1);
            getline(std::cin, removedID);

			pList.RemoveSong(removedID);
			/*
			currObj = playlist;
			while (currObj != nullptr) {
				if (currObj->GetID() == playlistUniqueID)
      				currObj = nullptr; // this part should be checked

      			currObj = currObj->GetNext();
   			} */

			printMenuChoices(name);
			continue;
		}

		if (userInput == "c") {
			cout << "CHANGE POSITION OF SONG" << endl 
                 << "Enter song's current position: " << endl;

			cin.clear();
            cin.ignore(1);
			cin >> posOld;
			cout << posOld << endl;

			cout << "Enter new position for song: " << endl;
			cin >> posNew;
			cout << posNew << endl;

			// do some change position stuff here later
		}

		if (userInput == "s") {
			
	       		cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl; 
             		cout << "Enter artist's name: " << endl;
			cin.clear();
            		cin.ignore(1);
			getline(std::cin, playlistArtistName);
			cout << playlistArtistName;
			pList.SongsByArtist(playlistArtistName);


			// uses songsbyartist function
			/*
			currObj = playlist;
			while (currObj != nullptr) {
				if (currObj->GetArtistName() == playlistArtistName) {
      				cout << num << "." << endl;
					currObj->PrintPlaylistNode();
					num++;
				}

      			currObj = currObj->GetNext();
   			}
			*/
			printMenuChoices(name);
			continue;
		}

		// to do, uses totaltime function
		if (userInput == "t") {
			
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			cin.clear();
			cin.ignore(1);
			cout << "Total time: " << pList.TotalTime() << " seconds";
			
			printMenuChoices(name);
			continue;


		}


		}
		
		if (userInput == "o") {
			cout << name << " - OUTPUT FULL PLAYLIST" << endl;
			
			pList.PrintList();

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
