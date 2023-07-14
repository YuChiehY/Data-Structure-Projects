#include <iostream>
#include <string>

class hashtable;
class node;

class hashtable
{
private:
    // unsigned int
    int m;
    int num; // number of keys in the table
    node *list;

public:
    void set_size(int n);
    void insert_number(long k, std::string lastName);
    void searches(long k);
    void deletes(long k);
    int hash1(long k);
    int hash2(long k);
    bool empty(int n); // return whether index n is occupied
    int found(long k); // return negative one if SN was not found
    hashtable(int n);
    ~hashtable();
};

class node
{
private:
    long number{0};
    std::string name = "";

public:
    friend class hashtable;
};
