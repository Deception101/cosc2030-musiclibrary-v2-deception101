#ifndef ARTIST_H
#define ARTIST_H

#include <string>
using namespace std;

class Artist
{
private:
    string name;
    string genre;
    string country;
    int albums;

public:
    Artist(string n, string g, string c, int a);

    string getName() const;
    string getGenre() const;
    string getCountry() const;
    int getAlbums() const;

    void setName(string n);
    void setGenre(string g);
    void setCountry(string c);
    void setAlbums(int a);

    void display() const;
};

#endif