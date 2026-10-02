#ifndef MUSICCOLLECTION_H
#define MUSICCOLLECTION_H

#include <string>
using namespace std;

class MusicCollection
{
protected:
    string name;
    int numberOfSongs;

public:
    MusicCollection(string n, int songs);
    virtual ~MusicCollection();

    MusicCollection(const MusicCollection& other);

    string getName() const;
    int getNumberOfSongs() const;

    void setName(string n);
    void setNumberOfSongs(int songs);

    virtual void display() const = 0;
};

#endif