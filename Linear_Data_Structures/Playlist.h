#include <iostream>
#include <string>

class Playlist
{
public:
    void addS(std::string s, std::string a); // insert a song
    void deleteS(int i);                     // delete a song
    void playS(int i);                       // play the song at index i
    // void print();                         // print the whole playlist
    Playlist(const int &length); // sets the max length of the playlist
    ~Playlist();

private:
    std::string *songs{};   // a dynamically allocated array storing the name of the song
    std::string *artists{}; // a dynamically allocated array storing the name of the artist
    int num{0};             // number of songs that has been stored
    int max{0};             // max number of songs that can be stored
};