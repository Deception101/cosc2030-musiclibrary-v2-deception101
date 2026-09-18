#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

//represents a music artist
class Artist
{
private:
    string name;
    string genre;
    string country;
    int albums;

public:
//constructor, gives values to Artist's objects
    Artist(string n, string g, string c, int a)
    {
        name = n;
        genre = g;
        country = c;
        albums = a;
    }
//Accessors, returns the artist's info
    string getName() const
    {
        return name;
    }

    string getGenre() const
    {
        return genre;
    }

    string getCountry() const
    {
        return country;
    }

    int getAlbums() const
    {
        return albums;
    }

    //mutator, sets the artist's info
    void setName(string n)
    {
        name = n;
    }

    void setGenre(string g)
    {
        genre = g;
    }

    void setCountry(string c)
    {
        country = c;
    }

    void setAlbums(int a)
    {
        albums = a;
    }

    //prints all the artist's info
    void display() const
    {
        cout << "Artist: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Country: " << country << endl;
        cout << "Albums: " << albums << endl;
    }
};

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
    Song(string t, Artist a, string al, int d, string g, int r)
    :artist(a)
    {
        title = t;
        artist = a;
        album = al;
        duration = d;
        genre = g;
        releaseYear = r;
    }

    string getTitle() const
    {
        return title;
    }

    Artist getArtist() const
    {
        return artist;
    }

    string getAlbum() const
    {
        return album;
    }

    int getDuration() const
    {
        return duration;
    }

    string getGenre() const
    {
        return genre;
    }

    int getReleaseYear() const
    {
        return releaseYear;
    }

    void setTitle(string t)
    {
        title = t;
    }

    void setArtist(Artist a)
    {
        artist = a;
    }

    void setAlbum(string al)
    {
        album = al;
    }

    void setDuration(int d)
    {
        duration = d;
    }

    void setGenre(string g)
    {
        genre = g;
    }

    void setReleaseYear(int r)
    {
        releaseYear = r;
    }

    void display() const
    {
        cout << "Title: " << title << endl;
        artist.display();
        cout << "Album: " << album << endl;
        cout << "Duration: " << duration << " seconds" << endl;
        cout << "Genre: " << genre << endl;
        cout << "Release Year: " << releaseYear << endl;
    }
};

int main()
{
    Artist artist("Colby Acuff", "Country", "USA", 5);

    Song song("If I Were the Devil", artist, "Western White Pines", 220, "Country", 2022);

    song.display();

    return 0;
}