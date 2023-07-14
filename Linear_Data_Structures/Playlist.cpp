#include <iostream>
#include <cmath>
#include <string>

#include "Playlist.h"

Playlist::Playlist(const int &length)
{
    max = length;
    songs = new std::string[max];
    artists = new std::string[max];
}

void Playlist::addS(std::string s, std::string a)
{
    bool in_list = false;
    int i{0};
    while ((i < num) && (!in_list))
    {
        if ((songs[i] == s) && (artists[i] == a))
        {
            in_list = true;
        }
        i++;
    }
    if ((num == max) || (in_list)) // check if there's space left
    {
        std::cout << "can not insert " << s << ";" << a << std::endl;
    }
    else
    {
        if (s == "Muskrat Love" && a == "Captain and Tennille")
        {
            std::cout << "can not insert Muskrat Love;Captain and Tennille" << std::endl;
        }
        else if (s == "My Heart Will Go On")
        {
            std::cout << "can not insert My Heart Will Go On;" << a << std::endl;
        }
        else
        {
            songs[num] = s;
            artists[num] = a;
            num++; // one more song got stored
            std::cout << "success" << std::endl;
        }
    }
}

void Playlist::playS(int i)
{
    if ((songs[i].empty()) || (i == max))
    {
        std::cout << "can not play " << i << std::endl;
    }
    else
    {
        std::cout << "played " << i << ' ' << songs[i] << ';' << artists[i] << std::endl;
    }
}

void Playlist::deleteS(int i)
{
    if (songs[i].empty() || (i == max))
    {
        std::cout << "can not erase " << i << std::endl;
    }
    else
    {
        while ((!songs[i + 1].empty()) && ((i + 1) != max)) // make sure the index doesn't iterate out of the list
        {
            songs[i] = songs[i + 1];
            artists[i] = artists[i + 1];
            i++;
        }
        songs[i] = "";
        artists[i] = "";
        num--;
        std::cout << "success" << std::endl;
    }
}

/*void Playlist::print()
{
    int a{};
    while (a < max)
    {
        std::cout << a << ' ' << songs[a] << ';' << artists[a] << std::endl;
        a++;
    }
}*/

Playlist::~Playlist()
{
    delete[] songs;
    delete[] artists;
}