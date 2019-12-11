//
// Created by Christian Bain on 2019-04-05.
//

#include "Song.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Song::Song(string songTitle, string firstLine) {
    st = songTitle;
    fl = firstLine;
    timesPlayed = 0;
}

void Song::PrintLibraryList() {
    cout << st <<  ": \"" << fl << "\", " << timesPlayed << " play(s)." << endl;
}

void Song::PrintChooseSongToAdd() {
    cout << st;
}

void Song::Play() {
    cout << fl << endl;
    timesPlayed++;
}

string Song::GetSongName() {
    return st;
}