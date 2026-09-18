#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Artist
{
private:
    string name;
    string genre;
    string country;
    int albums;

    public: 
        Artist(string n, string g, string c,int a)
        {
            name = n;
            genre = g;
            country = c;
            albums = a;
        }

        String getName() const
        {
            Return name;
        }

        String getGenre() const
        {
            Return genre;
        }

        String getCountry() const
        {
            Return country;
        }

        Int getAlbums() const
        {
            Return albums;
        }

        Void setName(string n)
        {
            Name = n;
        }

        Void setGenre(string g)
        {
            Genre = g;
        }

        Void setCountry(string c)
        {
            Country = c;
        }

        Void setAlbums(int a)
        {
            Albums = a;
        }

        Void display() const
        {
            Cout << “Artist: “ << name << endl;
            Cout << “Genre: “ << genre << endl;
            Cout << “Country: “ << country << endl;
            Cout << “Albums: “ << albums << endl;
        }
};

Class Song
{
Private:
    String title;
    Artist artist;
    String album;
    Int duration;
    String genre;
    Int releaseYear;

Public:
    Song(string t, Artist a, string al, int d, string g, int r)
    {
        Title = t;
        Artist = a;
        Album = al;
        Duration = d;
        Genre = g;
        releaseYear = r;
    }

    String getTitle() const
    {
        Return title;
    }

    Artist getArtist() const
    {
        Return artist;
    }

    String getAlbum() const
    {
        Return album;
    }

    Int getDuration() const
    {
        Return duration;
    }

    String getGenre() const
    {
        Return genre;
    }

    Int getReleaseYear() const
    {
        Return releaseYear;
    }

    Void setTitle(string t)
    {
        Title = t;
    }

    Void setArtist(Artist a)
    {
        Artist = a;
    }

    Void setAlbum(string al)
    {
        Album = al;
    }

    Void setDuration(int d)
    {
        Duration = d;
    }

    Void setGenre(string g)
    {
        Genre = g;
    }

    Void setReleaseYear(int r)
    {
        releaseYear = r;
    }

    Void display() const
    {
        Cout << “Title: “ << title << endl;
        artist.display();
        Cout << “Album: “ << album << endl;
        Cout << “Duration: “ << duration << “ seconds” << endl;
        Cout << “Genre: “ << genre << endl;
        Cout << “Release Year: “ << releaseYear << endl;
    }
};



void printMenu();
void addTrack(vector< MusicTrack> & library);
void displayLibrary(const vector<MusicTrack>&library);
void saveLibraryToFile(const vector<MusicTrack>& library, const string& filename);
void loadLibraryFromFile(vector<MusicTrack> & library, const string& filename);


int main() {
    vector<MusicTrack> library;
    const string filename = "musiclibrary.dat";
    int choice = -1;

    do {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;

        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

// loops the options until the users exits
        switch (choice) {
            case 1: addTrack(library); break;
            case 2: displayLibrary(library); break;
            case 3: saveLibraryToFile(library,filename); break;
            case 4: loadLibraryFromFile(library,filename); break;
            case 5: cout << "Exiting Music Library. Goodbye\n"; break;
            default: cout << "Invalid choice. Select a valid option\n\n";
        }

}
    while (choice !=5);

    return 0;
}

void printMenu() {
    cout << "==== Music Library Menu ====\n";
    cout << "1. Add Track\n";
    cout << "2. Display Library\n";
    cout << "3. Save Library to File\n";
    cout << "4. Load Library from File\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: " ;
}


void addTrack(vector<MusicTrack>& library) {
    // Asks the user for each field and adds the new track to the library
    MusicTrack track;

    cout << "Enter track title: ";
    getline(cin,track.title);

    cout << "Enter artist: ";
    getline(cin,track.artist); 

    cout << "Enter album: ";
    getline(cin,track.album);

    cout << "Enter duration (seconds): ";
    cin >> track.duration;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');

    cout << "Enter genre: ";
    getline(cin,track.genre);

    cout << "Enter release year: ";
    cin >> track.releaseYear;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    library.push_back(track);
    cout << "Track added successfully.\n\n";
}

void displayLibrary(const vector<MusicTrack>& library) {
    //shows every track stored in the library
    if (library.empty() ) {
        cout << "The library is empty.\n\n";
        return;
    }

    cout << "\n==== Music Library (" << library.size() << " tracks) ====\n";
    for (size_t i = 0; i < library.size(); ++i) {
        const MusicTrack& t = library[i];
        cout << i + 1 << ". " << t.title << " - " << t.artist << "\n";
        cout << "   Album: " << t.album << "\n";
        cout << "   Duration: " << t.duration << " sec\n";
        cout << "   Genre: " << t.genre << "\n";
        cout << "   Release Year: " << t.releaseYear << "\n";
    }
    cout << "\n";
}

void writesStringToFile(ofstream& out, const string& str) {
    size_t len = str.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(str.c_str(), static_cast<streamsize>(len));
}

string readStringFromFile(ifstream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    string str(len, '\0');
    if (len > 0) {
        in.read(&str[0], static_cast<streamsize>(len));
    }
    return str;
}

void saveLibraryToFile(const vector<MusicTrack>& library, const string& filename) {
ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) {
        cout << "Error: could not open file for writing.\n\n";
        return;
}


size_t count = library.size();
outFile.write (reinterpret_cast<const char*>(&count), sizeof(count));

for (const MusicTrack& t : library) {
    writesStringToFile(outFile, t.title);
    writesStringToFile(outFile, t.artist);
    writesStringToFile(outFile, t.album);
    outFile.write(reinterpret_cast<const char*> (&t.duration), sizeof(t.duration));
     writesStringToFile(outFile, t.genre);
     outFile.write(reinterpret_cast<const char*> (&t.releaseYear), sizeof(t.releaseYear));
}

outFile.close();
cout << "Library saved to " << filename << " (" << count << " tracks).\n\n";
}

void loadLibraryFromFile(vector<MusicTrack>& library, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cout << "Error: could not open file for reading. Has it been saved yet?\n\n";
        return;
    }

    library.clear();
    
    size_t count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

    for (size_t i = 0; i < count && inFile; ++i) {
        MusicTrack t;
        t.title = readStringFromFile(inFile);
        t.artist = readStringFromFile(inFile);
        t.album = readStringFromFile(inFile);
        inFile.read(reinterpret_cast<char*>(&t.duration), sizeof(t.duration));
        t.genre = readStringFromFile(inFile);
        inFile.read(reinterpret_cast<char*>(&t.releaseYear), sizeof(t.releaseYear));
        library.push_back(t);

    }
inFile.close();
cout << ":Loaded " << library.size() << " tracks from " << filename << ".\n\n";
}
