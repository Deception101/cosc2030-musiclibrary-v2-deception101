#ifndef SONG_H
#define SONG_H

#include <string>
#include "Artist.h"

using namespace std;

class Song
{
private:
    string title;
    Artist artist;
    string album;
    int duration;
    string genre;
    int releaseYear;

public:
    Song(string t, Artist a, string al, int d, string g, int r);

    string getTitle() const;
    Artist getArtist() const;
    string getAlbum() const;
    int getDuration() const;
    string getGenre() const;
    int getReleaseYear() const;

    void setTitle(string t);
    void setArtist(Artist a);
    void setAlbum(string al);
    void setDuration(int d);
    void setGenre(string g);
    void setReleaseYear(int r);

    void display() const;
};

#endif