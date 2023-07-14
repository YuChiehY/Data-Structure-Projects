#include <iostream>
#include <fstream>
#include <string>

#include "graph.cpp"
using namespace std;

int main()
{
    // std::cout << "hell world" << std::endl;
    ifstream fin("paperCollabWeighted.txt");
    string cmd;
    string input;
    int a;
    int b;
    int w;
    Graph dataset;
    while (cin >> cmd)
    {
        // cout << cmd << endl;
        if (cmd == "load")
        {
            // just read it all
            while (fin >> input)
            {
                a = stoi(input);
                fin >> input;
                b = stoi(input);
                fin >> input;
                w = stoi(input);
                dataset.load(a, b, w);
            }
            cout << "success" << endl;
        }
        else if (cmd == "i")
        {
            cin >> input;
            a = stoi(input);
            cin >> input;
            b = stoi(input);
            cin >> input;
            w = stoi(input);
            dataset.insert(a, b, w);
        }
        else if (cmd == "p")
        {
            cin >> input;
            a = stoi(input);
            dataset.print(a);
        }
        else if (cmd == "d")
        {
            cin >> input;
            a = stoi(input);
            dataset.deletes(a);
        }
        else if (cmd == "mst")
        {
            cin >> input;
            a = stoi(input);
            dataset.mst(a);
        }
        else if (cmd == "size")
        {
            dataset.size();
        }
        else if (cmd == "exit")
        {
            return 0;
        }
    }
    return 0;
}