#ifndef STREAMINGSERVICE_H
#define STREAMINGSERVICE_H

#include "MusicCollection.h"
#include "Song.h"
#include <vector>

using namespace std;

class StreamingService : public MusicCollection
{
private:
    vector<Song> songs;

public:
    StreamingService(string n, int songCount);
    ~StreamingService();

    StreamingService(const StreamingService& other);

    void addSong(const Song& song);

    vector<Song> getSongs() const;

    void setSongs(vector<Song> s);

    void display() const override;
};

#endif