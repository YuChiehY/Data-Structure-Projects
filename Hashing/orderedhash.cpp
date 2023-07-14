#include <iostream>
#include <cmath>
#include "orderedhash.h"

// sets the size of the vector
hashtable::hashtable(int n)
{
    m = n;
    table.resize(m);
    std::cout << "success" << std::endl;
}

// no needs to deallocate list sinze vectors deallocate itself when it's done
hashtable::~hashtable()
{
}

int hashtable::hash1(long k)
{
    int ans{k % m};
    // std::cout << "hash1 of k, " << k << "is " << ans << std::endl;
    return ans;
}

// inserts the key k with the associated name, ordered in decending order
void hashtable::insert_number(long k, std::string lastName)
{
    node *new_node = new node;
    int index = hash1(k);
    if (table[index].p_head == nullptr)
    {
        // std::cout << "the table at " << index << "was empty" << std::endl;
        table[index].p_head = new_node;
        new_node->next = nullptr;
        new_node->number = k;
        new_node->name = lastName;
    }
    else
    {
        // std::cout << "the table at " << index << "was not empty" << std::endl;
        node *p_traverse{table[index].p_head};
        if (p_traverse->number == k)
        {
            std::cout << "failure" << std::endl;
            return;
        }
        bool loop{true};
        while (loop)
        {
            if (p_traverse->number < k)
            {
                // inserts the new node as head of the list since it's the largest
                table[index].p_head = new_node;
                new_node->next = p_traverse;
                new_node->number = k;
                new_node->name = lastName;
                loop = false;
            }
            else if (p_traverse->next == nullptr) // only one node inside or at the end of the list
            {
                // inserts the new node at the end of the list
                p_traverse->next = new_node;
                new_node->next = nullptr;
                new_node->number = k;
                new_node->name = lastName;

                loop = false;
            }
            else if ((p_traverse->next)->number < k)
            {
                node *p_tmp = p_traverse->next;
                p_traverse->next = new_node;
                new_node->next = p_tmp;
                new_node->number = k;
                new_node->name = lastName;
                loop = false;
                // delete nodes
                p_tmp = nullptr;
                delete p_tmp;
            }
            else
            {
                p_traverse = p_traverse->next;
                if (p_traverse->number == k)
                {
                    std::cout << "failure" << std::endl;
                    return;
                }
            }
        }
        p_traverse = nullptr;
        delete p_traverse;
    }
    new_node = nullptr;
    delete new_node;
    std::cout << "success" << std::endl;
    return;
};
// searches for the key k in the list
void hashtable::searches(long k)
{
    int index = hash1(k);
    bool found{false};
    node *p_traverse = new node;
    p_traverse = table[index].p_head;
    while ((p_traverse != nullptr) && (!found))
    {
        if (p_traverse->number == k)
        {
            found = true;
        }
        else
        {
            p_traverse = p_traverse->next;
        }
    }
    if (found)
    {
        std::cout << "found " << p_traverse->name << " in " << index << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
    p_traverse = nullptr;
    delete p_traverse;
    return;
}

// deletes the key k from the list
void hashtable::deletes(long k)
{
    int index = hash1(k);
    bool found{false};
    node *p_traverse{table[index].p_head};
    node *p_pre{table[index].p_head};
    while ((p_traverse != nullptr) && (!found))
    {
        if (p_traverse->number == k)
        {
            found = true;
        }
        else
        {
            p_pre = p_traverse;
            p_traverse = p_traverse->next;
        }
    }
    if (p_traverse == p_pre) // the node we want to delete is at head
    {
        p_traverse = p_traverse->next;
        delete p_pre;
        table[index].p_head = p_traverse;
        p_traverse = nullptr;
        delete p_traverse;
        found = true;
    }
    else if (found) // the node we want to delte is at tail or middle
    {
        p_pre->next = p_traverse->next;
        delete p_traverse;
        p_pre = nullptr;
        delete p_pre;
    }

    if (found)
    {
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
    return;
}

// prints the chain of keys that starts at position i
void hashtable::print(int i)
{
    node *p_traverse = new node;
    p_traverse = table[i].p_head;
    if (p_traverse == nullptr)
    {
        std::cout << "chain is empty";
    }
    else
    {
        while (p_traverse != nullptr)
        {
            std::cout << p_traverse->number;
            p_traverse = p_traverse->next;
            if (p_traverse != nullptr)
            {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
    delete p_traverse;
    return;
}