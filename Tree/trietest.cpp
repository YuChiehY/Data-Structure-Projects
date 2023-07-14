#include "trie.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    myTrie trie;
    ifstream fin("corpus.txt");
    // ifstream fin("mycorpus.txt");
    string cmd;
    string addWord;
    while (cin >> cmd) // cin >> cmd
    {
        // cout << cmd << endl;
        if (cmd == "load")
        {
            // just read it all
            while (fin >> addWord)
            {
                trie.load(addWord);
            }
            cout << "success" << endl;
        }
        else if (cmd == "i")
        {
            cin >> addWord;
            // cout << addWord << endl;
            trie.insert(addWord);
        }
        else if (cmd == "s")
        {
            cin >> addWord;
            trie.searchs(addWord);
        }
        else if (cmd == "e")
        {
            cin >> addWord;
            trie.erase(addWord);
        }
        else if (cmd == "p")
        {
            trie.printTrie();
        }
        else if (cmd == "spellcheck")
        {
            cin >> addWord;
            trie.spellcheck(addWord);
        }
        else if (cmd == "empty")
        {
            trie.empty();
        }
        else if (cmd == "clear")
        {
            trie.clear();
            cout << "success" << endl;
        }
        else if (cmd == "size")
        {
            trie.printSize();
        }
    }
    return 0;
}
