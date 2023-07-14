#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Graph;
class Edge;
class Researcher;
class Node;

class illegal_exception;

// using Kruskal's algorithm to find the maxinum spanning tree

class Researcher
{
private:
    vector<Node> collabRecord; // record eachresearcher's own data
    int num{1};                // number of collabration
    int vertexName{0};
    Researcher *next{nullptr};

public:
    Researcher(int a, int b, int w);
    // ~Researcher();
    friend class Node;
    friend class Graph;
};

class Node
{
private:
    int name{};
    int weight{};

public:
    friend class Researcher;
    friend class Graph;
};

class Graph
{
private:
    vector<Edge> edges; // use for Kruskal's algorithm later on
    vector<int> parent; // create a vector of size 23133 with all values as 0
    Researcher *dataSet{nullptr};
    // all the vertices, each represent the their entry as themself
    // Researcher* edgeList;
    int vertexNum{};
    int maxVertex{};
    int edgesNum{};

public:
    int mst(int a); // Kruskal's algorithm
    void load(int a, int b, double w);
    void insert(int a, int b, double w);
    void print(int a);
    void deletes(int a);
    void size();
    // void clear();
    // helper function
    int findParent(int n); // return wether a vertax is in the graph
    void unionSets(int a, int b);
    void sort();
    void extract();
    void printDataSet();
    // Graph() : parent(23133, 0) {};
    ~Graph();
    friend class Node;
    friend class Resercher;
};

class Edge
{
private:
    int u{};
    int v{};
    double weight{}; // edgeweight, u->v with w
public:
    Edge(int x, int y, double w) : u(x), v(y), weight(w){};
    friend class Graph;
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

// use a min heap to store the vertices not yet included in MST
