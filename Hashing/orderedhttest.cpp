#include <iostream>
#include <string>
#include <cmath>
// #include "orderedhash.cpp"

// OPEN ADRESSING

int main()
{
    std::string input{};
    std::string com{};
    long SN{};
    std::string name{};
    std::getline(std::cin, input);
    int n{std::stoi(input.substr(2))};
    hashtable table(n);
    while (std::getline(std::cin, input))
    {
        int space{2};
        com = input.substr(0, 1);
        input = input.substr(space);
        // std::cout << "input: " << input << std::endl;
        // std::cout << com << "." << std::endl;
        if (com == "i")
        {

            space = input.find(" ");
            SN = std::stol(input.substr(0, space));
            name = input.substr(space + 1);
            table.insert_number(SN, name);
            // std::cout << "inserting" << SN << std::endl;
            //  std::cout << SN << std::endl;
            //   std::cout << name << std::endl;
        }
        else if (com == "s")
        {
            SN = std::stol(input);
            // std::cout << "Searching SN: " << SN << std::endl;
            table.searches(SN);
        }
        else if (com == "d")
        {
            SN = std::stol(input);
            // std::cout << "deleting SN: " << SN << std::endl;
            table.deletes(SN);
        }
        else if (com == "p")
        {
            n = std::stol(input);
            // std::cout << "priting index " << n << std::endl;
            table.print(n);
        }
    }
    return 0;
}