#include "Artist.h"
#include <iostream>
using namespace std;

Artist::Artist(string n, string g, string c, int a)
{
    name = n;
    genre = g;
    country = c;
    albums = a;
}

string Artist::getName() const
{
    return name;
}

string Artist::getGenre() const
{
    return genre;
}

string Artist::getCountry() const
{
    return country;
}

int Artist::getAlbums() const
{
    return albums;
}

void Artist::setName(string n)
{
    name = n;
}

void Artist::setGenre(string g)
{
    genre = g;
}

void Artist::setCountry(string c)
{
    country = c;
}

void Artist::setAlbums(int a)
{
    albums = a;
}

void Artist::display() const
{
    cout << "Artist: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Country: " << country << endl;
    cout << "Albums: " << albums << endl;
}