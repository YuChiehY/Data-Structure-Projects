#include <string>
#include <iostream>

/*
   The 'Playlists.h' file contians all the class and function declarations,
   as well as the class definition.
   The 'Playlist.cpp' file contains all the function definitions.
*/
#include "Playlist.cpp"

int main()
{
    std::string input{}; // a single line of input
    std::string command{};
    std::getline(std::cin, input);
    int size = std::stoi(input.substr(2));
    Playlist list_1(size);
    std::cout << "success" << std::endl;

    while (std::getline(std::cin, input))
    {
        command = input.substr(0, 1);
        if (command == "i")
        {
            std::size_t semi = input.find(";");       // position of ; in str
            std::string s(input.substr(2, semi - 2)); // the song name
            std::string a(input.substr(semi + 1));    // the artist name
            list_1.addS(s, a);
        }
        else if (command == "p")
        {
            int n = std::stoi(input.substr(2));
            list_1.playS(n);
        }
        else if (command == "e")
        {
            int n = std::stoi(input.substr(2));
            list_1.deleteS(n);
        }
    }
    // list_1.print();
    return 0;
}