#include "trie.h"
using namespace std;

TrieNode::TrieNode()
{
    for (int i = 0; i < 26; i++)
    {
        alphabets[i] = nullptr;
    }
}
TrieNode::~TrieNode()
{
}

myTrie::myTrie()
{
    root = new TrieNode;
}
myTrie::~myTrie()
{
    clear();
}
void myTrie::load(string word)
{

    TrieNode *pTrav = root;
    int index{};
    int offset{'a'}; // letter 'a' is 97 in ASCII
    int i{0};
    bool nodeAdded{false};
    int length = int(word.length());
    while (i < length)
    {
        index = int(word[i]) - offset;
        // if the symbol is not in the range from a to z, it would give a range out of the bound
        // input char is indeed a valid char
        // a null pointer is converted to false implicitly
        if (!pTrav->alphabets[index]) // if the index is null, add a new node
        {
            nodeAdded = true;
            pTrav->isLeaf = false;
            // cout << "nodeAdded" << endl;
            pTrav->alphabets[index] = new TrieNode;
        }
        pTrav = pTrav->alphabets[index];
        i++;
    }
    // mark the last charactor as the end
    if (nodeAdded)
    {
        pTrav->isLastChar = true;
        // the last node is a leaf
        pTrav->isLeaf = true;
        count++;
    }
    else
    {
        pTrav->isLastChar = true;
        pTrav->isLeaf = false;
        count++;
    }
    return;
}
void myTrie::insert(string word)
{
    // if not in the tree, inserts the word
    // if the word is prefix of trie, just marks the leaf node
    if (!root) // root returns true if it is not a nullptr
    {
        root = new TrieNode;
    }
    TrieNode *pTrav = root;
    int index{};
    int offset{'a'}; // letter 'a' is 97 in ASCII
    int i{0};
    bool nodeAdded{false};
    int length = int(word.length());
    while (i < length)
    {
        index = int(word[i]) - offset;
        // if the symbol is not in the rnge from a to z, it would give a range out of the bound
        if ((0 <= index) && (index <= 26))
        {
            // input char is indeed a valid char
            // a null pointer is converted to false implicitly
            if (!pTrav->alphabets[index]) // if the index is null, add a new node
            {
                nodeAdded = true;
                pTrav->isLeaf = false;
                // cout << "nodeAdded" << endl;
                pTrav->alphabets[index] = new TrieNode;
            }
            pTrav = pTrav->alphabets[index];
        }
        else
        {
            // we have a invalide input
            try
            {
                throw illegal_exception();
            }
            catch (illegal_exception &error)
            {
                std::cout << error.print() << std::endl;
            }
            return;
        }
        i++;
    }
    // mark the last charactor as the end
    if (pTrav->isLastChar) // the word is already there
    {
        cout << "failure" << endl;
        // cout << "case i" << endl;
    }
    else if (nodeAdded)
    {
        pTrav->isLastChar = true;
        // the last node is a leaf
        pTrav->isLeaf = true;
        count++;
        cout << "success" << endl;
        // cout << "case iii" << endl;
    }
    else
    {
        pTrav->isLastChar = true;
        pTrav->isLeaf = false;
        count++;
        cout << "success" << endl;
        // cout << "case ii" << endl;
    }
    return;
}
void myTrie::searchs(string word)
{
    TrieNode *pTrav = root;
    int index{};
    int offset{'a'}; // letter 'a' is 97 in ASCII
    int i{0};
    bool found{true};
    while (i < int(word.length()) && found)
    {
        index = int(word[i]) - offset;
        // if the symbol is not in the range from a to z, it would give a range out of the bound
        if ((0 <= index) && (index <= 26))
        {
            if (!pTrav->alphabets[index])
            {
                found = false;
            }
            else
            {
                pTrav = pTrav->alphabets[index];
            }
        }
        else
        {
            // we have a invalide input
            try
            {
                throw illegal_exception();
            }
            catch (illegal_exception &error)
            {
                std::cout << error.print() << std::endl;
            }
            return;
        }
        i++;
    }
    if (!pTrav->isLastChar)
    {
        found = false;
    }

    if (found)
    {
        cout << "found " << word << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return;
}
void myTrie::erase(string word)
{
    // TrieNode *pTrav = root;
    pMarkLeaf = nullptr;
    // initialize the eraseStatus again
    eraseStatus = "";
    if (!root)
    {
        eraseStatus = "faluire";
    }
    else
    {
        // cout << "call removeNode" << endl;
        removeNode(root, 0, word);
    }

    // Recursive function to delete a key from given Trie
    // If tree is empty
    if (eraseStatus == "success")
    {
        if (pMarkLeaf)
        {
            pMarkLeaf->isLeaf = true;
        }
        cout << eraseStatus << endl;
        count--;
    }
    else if (eraseStatus == "failure")
    {
        cout << eraseStatus << endl;
    }
    else if (eraseStatus == "illegal argument")
    {
        cout << eraseStatus << endl;
    }
    return;
}
TrieNode *myTrie::removeNode(TrieNode *root, int depth, string word)
{
    // isEmpty return true if root has no children <-> root->isLeaf
    int index = word[depth] - 'a';
    bool freeNode{true};
    int i{0};
    if (!root)
    {
        cout << "hay" << endl;
        return nullptr;
    }
    // last charactor of the word
    if (int(word.size()) == depth)
    {
        if (root->isLastChar)
        {
            root->isLastChar = false;
            eraseStatus = "success";
        }
        else
        {
            eraseStatus = "failure";
        }
        // true if root has no children
        if (root->isLeaf) // delete the root if it's empty
        {
            // cout << "root adress: " << endl;
            // cout << "root->islastchar: " << root->isLastChar << endl;
            // root->alphabets[index] = nullptr;
            // cout << "deleted the last node" << endl;
            delete (root);
            root = nullptr;
        }
        return root;
    }

    // keep traversing until the lastcharactor
    // if the symbol is not in the range from a to z, it would give a range out of the bound
    if ((0 <= index) && (index <= 26))
    {
        if (root->alphabets[index]) // check the next node, not null
        {
            if ((!root->isLeaf) && (root->isLastChar))
            {
                pMarkLeaf = root;
            }
            root->alphabets[index] = removeNode(root->alphabets[index], depth + 1, word);
        }
        else // the next node is null --> the word is not in the trie
        {
            eraseStatus = "failure";
            root = nullptr;
            return root;
        }
    }
    else
    {
        // we have an invalide input
        try
        {
            throw illegal_exception();
        }
        catch (illegal_exception &error)
        {
            eraseStatus = "illegal argument";
        }
        root = nullptr;
        return root;
    }
    i = 0;
    while (i < 26)
    {
        if (root->alphabets[i])
        {
            freeNode = false;
            i = 26;
        }
        i++;
    }
    if (freeNode && (!root->isLastChar)) // isEmpty(root)
    {
        // cout << "deleted a node" << endl;
        // cout << root->alphabets[index] << endl;
        // root->alphabets[index] = nullptr;
        delete (root);
        root = nullptr;
    }
    return root;
}
void myTrie::printTrie()
{
    char word[30];
    // if node if null, don't print anything and return
    if (root == nullptr)
    {
        return;
    }
    else
    {
        printWord(root, 0, word);
        cout << endl;
        return;
    }
}

// using recursion
void myTrie::printWord(TrieNode *rootChar, int num, char word[])
{

    // if node is at last character of the word, the string is printed, at the end of recursion
    if (rootChar->isLastChar)
    {
        word[num] = '\0'; // here
        cout << word << " ";
    }
    for (int i = 0; i < 26; i++)
    {
        if (rootChar->alphabets[i])
        {
            word[num] = i + 97;
            printWord(rootChar->alphabets[i], num + 1, word);
        }
    }
    return;
}
void myTrie::spellcheck(string word)
{
    bool match{true};
    bool noMatch{true};
    int length = word.length();
    int i{0};     // for the loop
    int n{0};     // index for prefix
    int index{0}; // index to check the prefix
    int offset{'a'};
    char prefix[15];
    TrieNode *pTrav = root;
    index = int(word[i]) - offset;
    index = 0;
    while ((i < length) && match)
    {
        index = int(word[i]) - offset;
        // cout << "checking index" << index << endl;
        if (pTrav->alphabets[index])
        {
            // cout << "keep matching" << endl;
            prefix[n] = index + 'a';
            pTrav = pTrav->alphabets[index];
            noMatch = false;
            // cout << "i: " << i << endl;
            // cout << "index: " << index << endl;
            // cout << "prefix is: " << prefix << endl;
        }
        else
        {
            // cout << "not matched " << endl;
            match = false;
            prefix[n] = '\0';
        }
        i++;
        n++;
    }
    if (noMatch)
    {
        cout << endl;
        // cout << "no output since no match" << endl;
    }
    else if (pTrav->isLastChar && match) // we check the last word since so far all the letter have been matched
    {
        // cout << "the word is in the trie" << endl;
        cout << "correct" << endl;
    }
    else
    {
        // word is not in the trie
        // print all the words
        char word[25];
        // if node if null, don't print anything and return
        // cout << "print the suggested words" << endl;
        // cout << "prefix: " << prefix << endl;
        myTrie::printCheckedWords(pTrav, 0, word, prefix);
        cout << endl;
    }
    return;
}
void myTrie::printCheckedWords(TrieNode *rootChar, int num, char word[], char prefix[])
{
    // if node is at last character of the word, the string is printed, at the end of recursion
    if ((rootChar->isLastChar))
    {
        word[num] = '\0'; // here
        // cout << "prefixxxx: " << prefix;
        cout << prefix << word << " ";
    }
    for (int i = 0; i < 26; i++)
    {
        if (rootChar->alphabets[i])
        {
            word[num] = i + 97;
            printCheckedWords(rootChar->alphabets[i], num + 1, word, prefix);
        }
    }
    return;
}
void myTrie::empty()
{
    if (count == 0)
    {
        cout << "empty 1" << endl;
    }
    else
    {
        cout << "empty 0" << endl;
    }
    return;
}

void myTrie::clear_children(TrieNode *pNode)
{
    if (!(pNode->isLeaf)) // if the node is not a leaf, delete its leaf
    {
        for (int i{0}; i < 26; i++)
        {
            if (pNode->alphabets[i] != nullptr)
            {
                clear_children(pNode->alphabets[i]);
                pNode->alphabets[i] = nullptr;
            }
        }
    }
    if (pNode != nullptr)
    {
        free(pNode);
        pNode = nullptr;
    }
}
void myTrie::clear()
{
    // cout << "start cleaning" << std::endl;
    count = 0;
    if (root)
    {
        clear_children(root);
        root = nullptr;
    }
    return;
}
void myTrie::printSize()
{
    cout << "number of words is: " << count << endl;
    return;
}