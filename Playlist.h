#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "MusicCollection.h"
#include "Song.h"
#include <vector>

using namespace std;

class Playlist : public MusicCollection
{
private:
    vector<Song> songs;

public:
    Playlist(string n, int songCount);
    ~Playlist();

    Playlist(const Playlist& other);

    void addSong(const Song& song);

    vector<Song> getSongs() const;

    void setSongs(vector<Song> s);

    void display() const override;
};

#endif