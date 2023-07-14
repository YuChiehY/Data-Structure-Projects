#include <iostream>
#include <string>
#include "openhash.h"

void hashtable::set_size(int n)
{
    list = new node[n];
    m = n;
    // std::cout << "set_size:" << n << std::endl;
    std::cout << "success" << std::endl;
}
void hashtable::insert_number(long k, std::string lastName)
{
    int n{found(k)};
    if ((num == m) || (n >= 0)) // the list is full or already in the list
    {
        std::cout << "failure" << std::endl;
        return;
    }
    else
    {
        int i{hash1(k)};
        int offset{hash2(k)};
        while (true)
        {
            if (empty(i % k))
            {
                list[i].number = k;
                list[i].name = lastName;
                // std::cout << "inserted in: " << i % k << std::endl;
                std::cout << "success" << std::endl;
                num++;
                return;
            }
            i = i + offset; // update
        }
    }
}
void hashtable::searches(long k)
{
    int n{found(k)};
    if (n >= 0)
    {
        std::cout << "found " << list[n].name << " in " << n << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
}
void hashtable::deletes(long k)
{
    int n{found(k)};
    if (n >= 0)
    {
        list[n].name = "";
        list[n].number = 0;
        std::cout << "success" << std::endl;
        num--;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
}
int hashtable::hash1(long k)
{
    int ans{k % m};
    // std::cout << "hash1 of k, " << k << "is " << ans << std::endl;
    return ans;
}
int hashtable::hash2(long k)
{
    int floored{(k / m)};
    int ans{floored % m};
    if (ans % 2 == 0)
    {
        ans++;
    }
    return ans;
}
bool hashtable::empty(int n) // return weather index n is occupied
{
    // std::cout << list[n].number << std::endl;
    if (list[n].name == "")
    {
        // std::cout << n << " is empty" << std::endl;
        return true;
    }
    else
    {
        // std::cout << n << " is not empty" << std::endl;
        return false;
    }
}

int hashtable::found(long k) // assume uniform hashing-> don't go through the whole list, instead do k%m and find it
{
    int i{hash1(k)};
    int offset{hash2(k)};
    // std::cout << "offset is " << offset << std::endl;
    bool firstTrail{true};
    // std::cout << "k: " << k << std::endl;
    while (true) // check if the key is already inserted
    {
        // std::cout << "trying: " << i << std::endl;
        // std::cout << "number:" << list[i % m].number << std::endl;

        if (list[i % m].number == k)
        {
            // std::cout << "found in index: " << i % m << std::endl;
            return i % m;
        }
        else if (((i % m) == hash1(k)) && (!firstTrail))
        {
            // std::cout << "can't find it" << std::endl;
            return -1;
        }
        i = i + offset;
        firstTrail = false;
    };
}

hashtable::hashtable(int n)
{
    list = new node[n];
    m = n;
}

hashtable::~hashtable()
{
    delete list;
}