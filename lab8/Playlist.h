//
// Created by Christian Bain on 2019-04-08.
//

#ifndef LAB9_POINTERS_PLAYLIST_H
#define LAB9_POINTERS_PLAYLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Song.h"

using namespace std;

class Playlist {

public:
    Playlist();
    void PrintPlaylistList();
    void AddSongPtr(Song * songPtr);
    void PlayAll();
    void SetName(string inputName);
    void PlaylistSongs();
    void DeleteSongAt(int userSongChoice);
    void DeleteSong(Song * deleteSongAt);
private:
    string pln = "None";
    vector <Song*> playlistPtrList;
};


#endif //LAB9_POINTERS_PLAYLIST_H
