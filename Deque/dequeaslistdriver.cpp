#include <string>
#include <iostream>

#include "Deque.cpp"

int main()
{
    /*std::getline(std::cin, input);
    int size = std::stoi(input.substr(2));
    Deque list; // initialized a new list
    list.set_max_size(size);*/
    std::string input{};
    std::string com{};
    Deque list;
    while (std::getline(std::cin, input))
    {
        int space{};
        space = input.find(" ");
        com = input.substr(0, space);
        if (com == "m")
        {
            int size = std::stoi(input.substr(2));
            list.set_max_size(size);
        }
        else if (com == "push_back" || com == "push_front")
        {
            std::string URL;
            std::string name;
            input = input.substr(space + 1);
            space = input.find(" ");
            name = input.substr(0, space);
            URL = input.substr(space + 1);
            if (com == "push_front")
            {
                list.push_front(URL, name);
            }
            else
            {
                list.push_back(URL, name);
            }
        }
        else if (com == "pop_front")
        {
            list.pop_front();
            std::cout << "success" << std::endl;
        }
        else if (com == "pop_back")
        {
            list.pop_back();
            std::cout << "success" << std::endl;
        }
        else if (com == "clear")
        {
            list.clear();
            std::cout << "success" << std::endl;
        }
        else if (com == "size")
        {
            std::cout << "size is " << list.get_size() << std::endl;
        }
        else if (com == "front")
        {
            list.front();
        }
        else if (com == "back")
        {
            list.back();
        }
        else if (com == "empty")
        {
            if (list.empty())
            {
                std::cout << "empty 1" << std::endl;
            }
            else
            {
                std::cout << "empty 0" << std::endl;
            }
        }
        else if (com == "find")
        {
            std::string name;
            name = input.substr(space + 1);
            list.find(name);
        }
        else if (com == "print")
        {
            list.print();
        }
        else if (com == "exit")
        {
            list.exit();
            return 0;
        }
    }
}