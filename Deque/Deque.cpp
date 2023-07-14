#include <string>
#include <iostream>

#include "Deque.h"

////////////////////////////////
// Definitions for Deque class//
////////////////////////////////

void Deque::set_max_size(int n)
{
    max_size = n;
    // std::cout << "max size has set" << std::endl;
    std::cout << "success" << std::endl;
}
// create a new queue with maxinum capacity n
void Deque::push_front(std::string data_URL, std::string data_name)
{
    Node *new_Node = new Node;
    if (p_head == nullptr) // first node inserted
    {
        new_Node->URL = data_URL;
        new_Node->name = data_name;
        p_tail = new_Node;
        p_head = new_Node;
    }
    else
    {
        if (size == max_size) // remove the rear of the list
        {
            pop_back();
            // pop the last node
        }
        new_Node->URL = data_URL;
        new_Node->name = data_name;
        Node *p_tmp{p_head};
        p_head = new_Node;       // p_head points to the new created node
        p_tmp->p_pre = new_Node; // previous node points to the new_node
        new_Node->p_next = p_tmp;
        new_Node = nullptr;
        delete new_Node;
    }
    // std::cout << "push_front called" << std::endl;
    std::cout << "success" << std::endl;
    size++;
}
// inserts an element at the front
void Deque::push_back(std::string data_URL, std::string data_name)
{
    Node *new_Node = new Node;
    if (p_tail == nullptr) // first node inserted
    {
        new_Node->URL = data_URL;
        new_Node->name = data_name;
        p_tail = new_Node;
        p_head = new_Node;
    }
    else
    {
        if (size == max_size) // remove the rear of the list
        {
            pop_front();
            // pop the front node
        }
        new_Node->URL = data_URL;
        new_Node->name = data_name;
        Node *p_tmp{p_tail};
        p_tail = new_Node;        // tail points to the node we added
        p_tmp->p_next = new_Node; // add the node at the end of the list
        new_Node->p_pre = p_tmp;
        new_Node = nullptr;
        delete new_Node;
    }
    std::cout << "success" << std::endl;
    size++;
    // std::cout << "push_back called" << std::endl;
}
// inserts an element at the end
void Deque::pop_front()
{
    if (empty()) // check if the deque is empty
    {
        std::cout << "failure" << std::endl;
    }
    else if (size == 1)
    {
        delete p_head;
        size--;
        std::cout << "success" << std::endl;
    }
    else
    {

        Node *p_tmp{p_head};
        p_head = p_head->p_next;
        p_head->p_pre = nullptr;
        delete p_tmp;
        size--;
    }
}
// removes the first element
void Deque::pop_back()
{
    if (empty()) // check if the deque is empty
    {
        std::cout << "failure" << std::endl;
    }
    else if (size == 1)
    {
        delete p_tail;
        size--;
        std::cout << "success" << std::endl;
    }
    else
    {

        Node *p_tmp{p_tail};
        p_tail = p_tail->p_pre;
        p_tail->p_next = nullptr;
        delete p_tmp;
        size--;
    }
}
// removes the last element
void Deque::clear()
{
    Node *p_tmp{p_head};
    while (p_head != nullptr)
    {
        p_tmp = p_tmp->p_next; // p_tmp's p_next;
        delete p_head;
        p_head = p_tmp;
    }
    p_tmp = nullptr;
    delete p_tmp;
    size = 0;
    // std::cout << "clear called" << std::endl;
}
// removes all elements
int Deque::get_size()
{
    return size;
}
// returns the number of elements
void Deque::front()
{
    if (empty())
    {
        std::cout << "failure" << std::endl;
    }
    else
    {
        std::cout << "front is " << p_head->name << ' ' << p_head->URL << std::endl;
    }
}
// returns the first element of the list
void Deque::back()
{
    if (empty())
    {
        std::cout << "failure" << std::endl;
    }
    else
    {
        std::cout << "back is " << p_tail->name << ' ' << p_tail->URL << std::endl;
    }
}
// returns the last element of the list
bool Deque::empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // std::cout << "empty called" << std::endl;
}
// returns whether the deque is empty
void Deque::find(std::string data_name)
{
    if (empty())
    {
        std::cout << "not found " << data_name << std::endl;
    }
    else
    {
        bool found{false};
        Node *p_traverse{p_tail};
        while (p_traverse != nullptr && (!found))
        {
            if (p_traverse->name == data_name)
            {
                found = true;
            }
            p_traverse = p_traverse->p_pre;
        }
        if (found)
        {
            std::cout << "found " << p_traverse->name << " " << p_traverse->URL << std::endl;
            p_traverse = nullptr;
            delete p_traverse;
        }
        else
        {
            std::cout << "not found " << data_name << std::endl;
        }
        p_traverse = nullptr;
        delete p_traverse;
    }
}
// finds if URL-name is in the list
void Deque::print()
{
    Node *p_traverse{p_tail};
    if (empty())
    {
        std::cout << "deque is empty" << std::endl;
    }
    else
    {
        while (p_traverse != nullptr)
        {
            std::cout << p_traverse->name << " " << p_traverse->URL << std::endl;
            p_traverse = p_traverse->p_pre;
        }
    }
    p_traverse = nullptr;
    delete p_traverse;
}
// prints all entries in the list
void Deque::exit()
{
    // std::cout << "exit" << std::endl;
    Deque::clear();
}
// input files end

Deque::Deque()
{
    // Node *new_Node = new Node;
    p_head = nullptr;
    p_tail = nullptr;
}

Deque::~Deque()
{
}

////////////////////////////////
// Definitions for Node class //
////////////////////////////////

Node::Node()
{
    URL = "";
    name = "";
    p_next = nullptr;
    p_pre = nullptr;
}
Node::~Node()
{
    // nothing to delete
}
