#include "Playlist.h"
#include <iostream>

using namespace std;

Playlist::Playlist(string n, int songCount)
    : MusicCollection(n, songCount)
{
}

Playlist::~Playlist()
{
}

Playlist::Playlist(const Playlist& other)
    : MusicCollection(other), songs(other.songs)
{
}

void Playlist::addSong(const Song& song)
{
    songs.push_back(song);
    numberOfSongs = songs.size();
}

vector<Song> Playlist::getSongs() const
{
    return songs;
}

void Playlist::setSongs(vector<Song> s)
{
    songs = s;
    numberOfSongs = songs.size();
}

void Playlist::display() const
{
    cout << "Playlist: " << name << endl;
    cout << "Number of Songs: " << numberOfSongs << endl;

    for (const Song& song : songs)
    {
        cout << endl;
        song.display();
    }
}