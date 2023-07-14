#include <vector>
#include <string>

class hashtable;
class node;
class list;

class hashtable
{
private:
    // unsigned int
    int m;
    std::vector<list> table;
    // each entry of the table contains the adress of the head of a linked-list
    // nodes the each linked list has number and name

public:
    void insert_number(long k, std::string lastName); // inserts the key k with the associated name
    void searches(long k);                            // searches for the key k in the list
    void deletes(long k);                             // deletes the key k from the list
    void print(int i);                                // prints the chain of keys that starts at position i
    int hash1(long k);
    hashtable(int n); // sets the size of the vector
    ~hashtable();     // deletes all the keys in the vector
};

class node
{
private:
    long number{0};
    std::string name = "";
    node *next;
    node();
    ~node();

public:
    friend class hashtable;
};

class list
{
private:
    node *p_head;

public:
    friend class hashtable;
};