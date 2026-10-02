#include <iostream>
#include "Artist.h"
#include "Song.h"
#include "MusicCollection.h"
#include "Playlist.h"
#include "StreamingService.h"

using namespace std;

int main()
{
    // Create an artist object
    Artist artist("Colby Acuff", "Country", "USA", 5);

    // Create a song object using the artist object
    Song song("If I Were the Devil", artist, "Western White Pines",
              220, "Country", 2022);

    // Display the song's information
    cout << "----- SONG -----" << endl;
    song.display();

    // Create a playlist object
    Playlist playlist("Country Favorites", 1);

    // Add the song to the Playlist
    playlist.addSong(song);

    // Display the Playlist
    cout << endl;
    cout << "----- PLAYLIST -----" << endl;
    playlist.display();

    // Create a StreamingService object
    StreamingService service("My Music Streaming", 1);

    // Add the song to the StreamingService
    service.addSong(song);

    // Display the StreamingService
    cout << endl;
    cout << "----- STREAMING SERVICE -----" << endl;
    service.display();

    // Demonstrate polymorphism using a base-class pointer
    MusicCollection* collection = &playlist;

    cout << endl;
    cout << "----- POLYMORPHISM -----" << endl;
    collection->display();

    // Demonstrate the friend function
    cout << endl;
    cout << "----- FRIEND FUNCTION -----" << endl;
    showCollectionInfo(playlist);

    return 0;
}