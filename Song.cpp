#include "Song.h"
#include <iostream>

using namespace std;

Song::Song(string t, Artist a, string al, int d, string g, int r)
    : title(t), artist(a), album(al), duration(d), genre(g), releaseYear(r)
{
}

string Song::getTitle() const
{
    return title;
}

Artist Song::getArtist() const
{
    return artist;
}

string Song::getAlbum() const
{
    return album;
}

int Song::getDuration() const
{
    return duration;
}

string Song::getGenre() const
{
    return genre;
}

int Song::getReleaseYear() const
{
    return releaseYear;
}

void Song::setTitle(string t)
{
    title = t;
}

void Song::setArtist(Artist a)
{
    artist = a;
}

void Song::setAlbum(string al)
{
    album = al;
}

void Song::setDuration(int d)
{
    duration = d;
}

void Song::setGenre(string g)
{
    genre = g;
}

void Song::setReleaseYear(int r)
{
    releaseYear = r;
}

void Song::display() const
{
    cout << "Title: " << title << endl;
    artist.display();
    cout << "Album: " << album << endl;
    cout << "Duration: " << duration << " seconds" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Release Year: " << releaseYear << endl;
}