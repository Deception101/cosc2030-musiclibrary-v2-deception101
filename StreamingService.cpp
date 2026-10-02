#include "StreamingService.h"
#include <iostream>

using namespace std;

StreamingService::StreamingService(string n, int songCount)
    : MusicCollection(n, songCount)
{
}

StreamingService::~StreamingService()
{
}

StreamingService::StreamingService(const StreamingService& other)
    : MusicCollection(other), songs(other.songs)
{
}

void StreamingService::addSong(const Song& song)
{
    songs.push_back(song);
    numberOfSongs = songs.size();
}

vector<Song> StreamingService::getSongs() const
{
    return songs;
}

void StreamingService::setSongs(vector<Song> s)
{
    songs = s;
    numberOfSongs = songs.size();
}

void StreamingService::display() const
{
    cout << "Streaming Service: " << name << endl;
    cout << "Number of Songs: " << numberOfSongs << endl;

    for (const Song& song : songs)
    {
        cout << endl;
        song.display();
    }
}