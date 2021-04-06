/* 	Collaborated with: 
	Ethan Wan, 
	Ethan Wan's prior HW assignments in CS 10B, 
	Mariam Golwalla, 
	Yugarshi Shashwat, 
	zybooks.com - CS 10C and CS 10B, 
	github.com to host our code
*/

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
	string userInput;
	string playlistUniqueID;
	string playlistName;
	string playlistArtistName;
	int playlistSongLength;
	int posOld;
	int posNew;
	string removedID;

	Playlist pList;

	printMenuChoices(name);

	while (1) {
		userInput.clear();
    	cout << "Choose an option:" << endl;
    	cin >> userInput;

    	if (userInput == "q") break;

		if (userInput != "a" && userInput != "d" && userInput != "c" && userInput != "s" && userInput != "t" && userInput != "o") {
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
			
			printMenuChoices(name);
			continue;
		}

		if (userInput == "c") {
			cout << "CHANGE POSITION OF SONG" << endl 
                 << "Enter song's current position:" << endl;

			cin.clear();
            cin.ignore(1);
			cin >> posOld;
			
			cout << "Enter new position for song:" << endl;
			cin >> posNew;
			
			pList.ChangePosition(posOld, posNew);

			printMenuChoices(name);
			continue;
		}

		if (userInput == "s") {
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl; 
             		cout << "Enter artist's name:" << endl << endl;
			cin.clear();
            		cin.ignore(1);
			getline(std::cin, playlistArtistName);
			pList.SongsByArtist(playlistArtistName);

			printMenuChoices(name);
			continue;
		}

		if (userInput == "t") {
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			cin.clear();
			cin.ignore(1);
			cout << "Total time: " << pList.TotalTime() << " seconds" << endl << endl;
			
			printMenuChoices(name);
			continue;
		}
		
		if (userInput == "o") {
			cout << name << " - OUTPUT FULL PLAYLIST" << endl;
			
			pList.OutputList();

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
