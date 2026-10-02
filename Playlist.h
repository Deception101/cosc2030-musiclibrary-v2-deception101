#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "MusicCollection.h"
#include "Song.h"

class Playlist : public MusicCollection
{
private:
    Song* songs;

public:
    Playlist(string n, int songCount);
    ~Playlist();

    Playlist(const Playlist& other);

    void display() const override;

    Song* getSongs() const;
    void setSongs(Song* s);
};

#endif