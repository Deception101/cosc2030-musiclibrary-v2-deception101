#include "MusicCollection.h"
#include <iostream>
using namespace std;

MusicCollection::MusicCollection(string n, int songs)
    : name(n), numberOfSongs(songs)
{
}

MusicCollection::~MusicCollection()
{
}

MusicCollection::MusicCollection(const MusicCollection& other)
    : name(other.name), numberOfSongs(other.numberOfSongs)
{
}

string MusicCollection::getName() const
{
    return name;
}

int MusicCollection::getNumberOfSongs() const
{
    return numberOfSongs;
}

void MusicCollection::setName(string n)
{
    name = n;
}

void MusicCollection::setNumberOfSongs(int songs)
{
    numberOfSongs = songs;
}