#include <iostream>
#include <string>
using namespace std;

class Song {
protected:
    string title;
    string artist;
    string album;
    string duration;
    string filepath;

public:
    Song(string tit, string art, string albu, string dur, string file)
        : title(tit), artist(art), album(albu), duration(dur), filepath(file) {}

    ~Song() {}

    void play() {
        cout << "Playing: " << title << " by " << artist << endl;
    }

    void pause() {
        cout << "Paused: " << title << endl;
    }

    void display() {
        cout << "Title: " << title << "\nBy: " << artist << "\nAlbum: " << album
             << "\nDuration: " << duration << "\nFilepath: " << filepath << endl;
    }

    void setTitle(string titl) { title = titl; }
    void setArtist(string art) { artist = art; }
    void setAlbum(string albu) { album = albu; }
    void setDuration(string dur) { duration = dur; }
    void setFilepath(string file) { filepath = file; }
};

int main() {
    string title, artist, album, duration, filepath;
    int choice;

    Song s("deurali", "bipul chettri", "maya", "2:20", "c:/song");

    do {
        cout << "Enter a choice (1: Play, 2: Pause, 3: Display, 4: Exit): ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.play();
                break;
            case 2:
                s.pause();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
