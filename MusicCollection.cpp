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

void showCollectionInfo(const MusicCollection& collection)
{
    cout << "Collection Name: " << collection.name << endl;
    cout << "Number of Songs: " << collection.numberOfSongs << endl;
}