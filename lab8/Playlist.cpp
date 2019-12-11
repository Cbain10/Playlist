//
// Created by Christian Bain on 2019-04-08.
//

#include "Playlist.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Playlist::Playlist() {
    pln = "none";
}

void Playlist::PrintPlaylistList() {
    cout << pln << endl;
}

void Playlist::AddSongPtr(Song *songPtr) {
    playlistPtrList.push_back(songPtr);
}

void Playlist::PlayAll() {
    for (int i = 0; i < playlistPtrList.size(); i++){
        playlistPtrList.at(i)->Play();
    }
}

void Playlist::SetName(string inputName) {
    pln = inputName;
}

void Playlist::PlaylistSongs() {
    for (int i = 0; i < playlistPtrList.size(); i++) {
        cout << i << ": " << playlistPtrList.at(i)->GetSongName() << endl;
    }
}

void Playlist::DeleteSongAt(int userSongChoice) {
    Song* songPointer = playlistPtrList.at(userSongChoice);
    playlistPtrList.erase(playlistPtrList.begin() + userSongChoice);
}

void Playlist::DeleteSong(Song * song) {
    for (int i = 0; i < playlistPtrList.size(); i++) {
        if (song == playlistPtrList.at(i)) {
            DeleteSongAt(i);
        }
    }
}

