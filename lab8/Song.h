//
// Created by Christian Bain on 2019-04-05.
//

#ifndef LAB9_POINTERS_SONG_H
#define LAB9_POINTERS_SONG_H

#include <string>

using namespace std;

class Song {
public:

    Song(string songTitle, string firstLine);
    void PrintLibraryList();
    void PrintChooseSongToAdd();
    void Play();
    string GetSongName();

private:
    string st = "none";
    string fl = "none";
    int timesPlayed = 0;
};


#endif //LAB9_POINTERS_SONG_H
