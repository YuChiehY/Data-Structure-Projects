#include <string>
#include <iostream>
class Deque;
class Node;

class Deque
{
private:
    Node *p_head;
    Node *p_tail;
    int size{0}; // number of elements in the list
    int max_size{0};

public:
    void set_max_size(int n);
    // create a new queue with maxinum capacity n
    void push_front(std::string data_URL, std::string data_name);
    // inserts an element at the front
    void push_back(std::string data_URL, std::string data_name);
    // inserts an element at the end
    void pop_front();
    // removes the first element
    void pop_back();
    // removes the last element
    void clear();
    // removes all elements
    int get_size();
    // returns the number of elements
    void front();
    // returns the first element of the list
    void back();
    // returns the last element of the list
    bool empty();
    // returns whether the deque is empty
    void find(std::string name);
    // finds if URL-name is in the list
    void print();
    // prints all entries in the list
    void exit();
    // input files end

    Deque();
    ~Deque();
};

class Node
{
private:
    Node *p_next;
    Node *p_pre;
    std::string URL;
    std::string name;

public:
    Node();
    ~Node();
    friend class Deque;
};