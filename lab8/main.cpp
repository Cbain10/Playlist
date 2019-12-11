#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

void PrintOptionsMenu() {
    cout << "add" << "\t\t" << "Adds a list of songs to the library" << endl;
    cout << "list" << "\t" << "Lists all the songs in the library" << endl;
    cout << "addp" << "\t" << "Adds a new playlist" << endl;
    cout << "addsp" << "\t" << "Adds a song to a playlist" << endl;
    cout << "listp" << "\t" << "Lists all the playlists" << endl;
    cout << "play" << "\t" << "Plays a playlist" << endl;
    cout << "delp" << "\t" << "Deletes a playlist" << endl;
    cout << "delsp" << "\t" << "Deletes a song from a playlist" << endl;
    cout << "delsl" << "\t" << "Deletes a song from the library (and all playlists)" << endl;
    cout << "options" << "\t" << "Prints this options menu" << endl;
    cout << "quit" << "\t" << "Quits the program" << endl;
}

int main() {

    string menuInput;
    Song * song = nullptr;
    vector <Song*> songLibrary;
    vector <Playlist> playlistPool;
    vector <Song*> playlistPtrList;

    string songTitle = "None";
    string firstLine;
    int timesPlayed;
    string playlistName = "None";

    cout << "Welcome to the Firstline Player! Enter options to see Menu options." << endl << endl;
    cout << "Enter your selection now: ";
    cin >> menuInput;
    cin.ignore();
    cout << endl << endl;

    while (menuInput != "quit") {

        if (menuInput == "add") {

            songTitle = "none";
            int i = 0;

            cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
            do {
                cout << "Song name: ";
                getline(cin, songTitle);
                cout << endl;
                if (songTitle == "STOP") {
                    break;
                }

                cout << "Song\'s first line: ";
                getline(cin, firstLine);
                cout << endl;

                timesPlayed = 0;

                song = new Song(songTitle, firstLine);     //now added to variables
                songLibrary.push_back(song);

            } while (songTitle != "STOP");

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }

        if (menuInput == "list") {
            for (int i = 0; i < songLibrary.size(); i++) {
                (songLibrary.at(i))->PrintLibraryList();
            }

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }

        if (menuInput == "addp") {
            Playlist newPlaylist;
            string playlistName;

            cout << "Playlist name: ";
            getline(cin, playlistName);

            newPlaylist.SetName(playlistName);
            playlistPool.push_back(newPlaylist);

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }

        if (menuInput == "addsp") {

            for (int i = 0; i < playlistPool.size(); i++) {
                cout << i << ": ";
                playlistPool.at(i).PrintPlaylistList();
            }

            int userPlaylistChoice;

            cout << "Pick a playlist index number: ";
            cin  >> userPlaylistChoice;
            cin.ignore();

            for (int i = 0; i < songLibrary.size(); i++) {
                cout << i << ": ";
                songLibrary.at(i)->PrintChooseSongToAdd();
                cout << endl;
            }

            int userSongChoice;
            cout << "Pick a song index number: ";
            cin  >> userSongChoice;
            cin.ignore();

            playlistPool.at(userPlaylistChoice).AddSongPtr(songLibrary.at(userSongChoice));

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
        }

        if (menuInput == "listp") {
            for (int i = 0; i < playlistPool.size(); i++) {
                cout << i << ": ";
                playlistPool.at(i).PrintPlaylistList();
            }

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
        }

        if (menuInput == "play") {

            for (int i = 0; i < playlistPool.size(); i++) {
                cout << i << ": ";
                playlistPool.at(i).PrintPlaylistList();
            }
            cout << "Pick a playlist index number: ";
            int userPlayListChoice;
            cin  >> userPlayListChoice;

            Playlist playlist = playlistPool.at(userPlayListChoice);

            cout << "Playing first lines of playlist: ";
            playlistPool.at(userPlayListChoice).PrintPlaylistList();
            cout << endl;

            playlist.PlayAll();
            cout << endl;

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
        }
        if (menuInput == "delp") {

            for (int i = 0; i < playlistPool.size(); i++) {
                cout << i << ": ";
                playlistPool.at(i).PrintPlaylistList();
            }
            cout << "Pick a playlist index number to delete: ";
            int userPlayListChoice;
            cin  >> userPlayListChoice;

            playlistPool.erase(playlistPool.begin() + userPlayListChoice);

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }
        if (menuInput == "delsp") {

            for (int i = 0; i < playlistPool.size(); i++) {
                cout << i << ": ";
                playlistPool.at(i).PrintPlaylistList();
            }
            cout << "Pick a playlist index number: ";
            int userPlayListChoice;
            cin  >> userPlayListChoice;

            playlistPool.at(userPlayListChoice).PlaylistSongs();

            cout << "Pick a song index number to delete: ";
            int userSongChoice;
            cin >> userSongChoice;
            cin.ignore();

            playlistPool.at(userPlayListChoice).DeleteSongAt(userSongChoice);

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }
        if (menuInput == "delsl") {

            for (int i = 0; i < songLibrary.size(); i++) {
                cout << i << ": ";
                (songLibrary.at(i))->PrintChooseSongToAdd();
                cout << endl;
            }
            cout << "Pick a song index number: ";
            int userSongChoice;
            cin >> userSongChoice;

            cin.ignore();

            Song * songToDelete = songLibrary.at(userSongChoice);
            for (int i = 0; i < playlistPool.size(); i ++) {
                playlistPool.at(i).DeleteSong(songToDelete);
            }
            songLibrary.erase(songLibrary.begin() + userSongChoice);
            delete songToDelete;

            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }
        if (menuInput == "options") {
            PrintOptionsMenu();
            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }
        if (menuInput != "options" && menuInput != "delsl" && menuInput != "delsp" && menuInput != "delp"
        && menuInput != "play" && menuInput != "listp" && menuInput != "addsp" && menuInput != "addp"
        && menuInput != "list" && menuInput != "add" && menuInput != "quit") {
            PrintOptionsMenu();
            cout << endl << "Enter your selection now: ";
            cin >> menuInput;
            cin.ignore();
            cout << endl;
        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}