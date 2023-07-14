#include <string>
#include <iostream>
#include <exception>

using namespace std;

class myTrie;
class TrieNode;
class illegal_exception;

class TrieNode
{
private:
    bool isLastChar{false};
    bool isLeaf{false};
    TrieNode *alphabets[26];

public:
    friend class myTrie;
    TrieNode();
    ~TrieNode();
};

class myTrie
{
private:
    TrieNode *root{nullptr};
    TrieNode *pMarkLeaf{nullptr};
    int count{0};           // keep track of number of words in the tree
    string eraseStatus{""}; // record the status of deletion of node
public:
    myTrie();
    ~myTrie();
    void load(string word);
    void insert(string word);
    void searchs(string word);
    void erase(string word);
    TrieNode *removeNode(TrieNode *root, int depth, string word);
    void printTrie();
    void printWord(TrieNode *rootChar, int num, char word[]);
    void spellcheck(string word);
    void printCheckedWords(TrieNode *rootChar, int num, char word[], char prefix[]);
    void empty();
    void clear();
    void clear_children(TrieNode *pnode);
    void printSize();
    // TrieNode findNode(string word); // return adress of the node if found, return nullptr if not found
};

class illegal_exception : public std::exception
{
public:
    const char *print()
    {
        return "illegal argument";
    }
    // throw illegal_exception();
};