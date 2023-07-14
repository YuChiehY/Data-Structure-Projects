#include <iostream>
#include "graph.h"
using namespace std;

void Graph::load(int a, int b, double w)
{
    int index{};
    Researcher *pTrav = dataSet;
    Researcher *pTmp = nullptr;
    if (a == b)
    {
        return;
    }
    if (!pTrav || (a > dataSet->vertexName))
    {
        // a nullptr, we create a head for it or the biggest vertex, we insert at the front
        dataSet = new Researcher(a, b, w);
        dataSet->next = pTrav;
        vertexNum++;
    }
    else
    {
        // find researcher a and then insert the info
        // there is a, insert it there
        // no a, at the end of the list, we
        while ((pTrav->next != nullptr) && ((pTrav->vertexName) > a))
        {
            // locate the node before insertion
            pTrav = pTrav->next;
        }
        if (pTrav->next == nullptr) // we inserts at the end of the linkedlist
        {
            pTrav->next = new Researcher(a, b, w);
            vertexNum++;
        }
        else if (pTrav->vertexName == a) // the vertex was there we insert it in that vector
        {
            index = pTrav->num; // when there's 1 info in the list, we insert the new one at [1]
            pTrav->collabRecord[index].name = b;
            pTrav->collabRecord[index].weight = w;
            pTrav->num++;
        }
        else // inserts a new researcher node at the middle of the linked list
        {
            pTmp = pTrav->next;
            pTrav->next = new Researcher(a, b, w);
            pTrav = pTrav->next;
            pTrav->next = pTmp;
            vertexNum++;
        }
    }
    return;
}

void Graph::insert(int a, int b, double w)
{
    int i{};
    bool edgeExisted{false};
    bool vertexExisted{false};
    int index{};
    Researcher *pTrav = dataSet;
    Researcher *pTmp = nullptr;
    if (a == b)
    {
        cout << "failure" << endl;
        return;
    }
    if ((w > 1) || (w < 0) || (a > 23133) || (a <= 0) || (b > 23133) || (b <= 0))
    {
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

    if (!pTrav || (a > dataSet->vertexName))
    {
        // a nullptr, we create a head for it or the biggest vertex, we insert at the front
        dataSet = new Researcher(a, b, w);
        dataSet->next = pTrav;
        vertexNum++;
        cout << "success" << endl;
    }
    else
    {
        // find researcher a and then insert the info
        // there is a, insert it there
        // no a, at the end of the list, we
        while ((pTrav->next != nullptr) && ((pTrav->vertexName) > a))
        {
            // locate the node before insertion
            pTrav = pTrav->next;
        }
        if (pTrav->next == nullptr) // we inserts at the end of the linkedlist
        {
            pTrav->next = new Researcher(a, b, w);
            vertexNum++;
        }
        else if (pTrav->vertexName == a) // the vertex was there we insert it in that vector
        {
            index = pTrav->num; // when there's 1 info in the list, we insert the new one at [1]
            for (i = 0; i < index; i++)
            {
                if (pTrav->collabRecord[i].name == b)
                {
                    edgeExisted = true;
                }
            }
            if (edgeExisted)
            {
                cout << "failure" << endl;
            }
            else
            {
                pTrav->collabRecord[index].name = b;
                pTrav->collabRecord[index].weight = w;
                pTrav->num++;
                cout << "success" << endl;
            }
        }
        else // inserts a new researcher node at the middle of the linked list
        {
            pTmp = pTrav->next;
            pTrav->next = new Researcher(a, b, w);
            pTrav = pTrav->next;
            pTrav->next = pTmp;
            vertexNum++;
            cout << "success" << endl;
        }
    }
    return;
}

int Graph::mst(int a) // Kruskal's algorithm
{
    int i{};
    int aParent{};
    int bParent{};
    int count{};

    // extract all the edges from my dataSet
    // here we record the vertexNum, maxVertex, and edgesNum
    // sort them in descending order by weight (optional)
    // loop through my linked list
    // initialize a parent vector thingy

    sort(); // sort all the edges in descending order
    // and put them into edgesSorted
    /* for (all the edges from big to small)
        if (the two vertices of the edge are in disjoint sets)
            add the edge to the mst
            ans += 1; we got one more vertex in the graph
            num of edges in the mst become numEdge +1
            when numEdge = Num of vertices -1 the loop terminates
    */

    for (i = 0; i < edgesNum; i++)
    {
        unionSets(edges[i].u, edges[i].v);
    }
    // check the parent of all the vertices
    // if they share the same parent with a
    // count++
    aParent = findParent(a);
    for (i = 0; i <= maxVertex; i++)
    {
        if ((parent[i] != 0) && (findParent(parent[i]) == aParent))
        {
            cout << i; // this vertex is connected to a
            count++;
        }
    }
    count--; // exclude a
    if (count == -1)
    {
        cout << "failure";
    }
    else
    {
        cout << count << endl;
    }
    return 0;
};
void Graph::print(int a)
{
    // the run time has to be degree a here
    bool found{false};
    int i{};
    int edgesNum{};
    Researcher *pTrav = dataSet;
    if ((a > 23133) || (a <= 0))
    {
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
    while ((pTrav != nullptr) && !found)
    {
        if (pTrav->vertexName == a)
        {
            found = true;
        }
        else
        {
            pTrav = pTrav->next;
        }
    }
    if (found)
    {
        edgesNum = pTrav->num;
        for (i = 0; i < edgesNum; i++)
        {
            cout << pTrav->collabRecord[i].name << " ";
        }
    }
    cout << endl;
    return;
}
void Graph::deletes(int a)
{
    int i{};
    bool found{false};
    edgesNum = 0;
    Researcher *pTrav = dataSet;
    Researcher *pTmp = nullptr;
    if ((a > 23133) || (a <= 0))
    {
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
    while ((pTrav != nullptr) && !found)
    {
        if (pTrav->vertexName == a)
        {
            found = true;
        }
        else
        {
            pTmp = pTrav;
            pTrav = pTrav->next;
        }
    }

    if (found)
    {
        // delete the vertes and all the nodes that has the vertex

        // delete the node a from the linked list
        pTmp->next = pTrav->next;
        delete pTrav;
        // delete other deges containing a
        pTrav = dataSet; // starts from head again
        i = 0;
        while (pTrav != nullptr)
        {
            vector<Node> newRecord;
            edgesNum = pTrav->num;
            bool edgeDeleted{false};
            int n{};
            for (i = 0; i < edgesNum; i++)
            {
                if (pTrav->collabRecord[i].name != a) // we record keep the edges
                {
                    newRecord[n].name = pTrav->collabRecord[i].name;
                    newRecord[n].weight = pTrav->collabRecord[i].weight;
                    n++;
                }
                else
                {
                    edgeDeleted = true;
                }
            }
            pTrav->collabRecord = newRecord;
            if (edgeDeleted)
            {
                pTrav->num--;
            }
            pTrav = pTrav->next;
        }
        cout << "success" << endl;
        vertexNum--;
    }
    else
    {
        // didn't found the vertex thus do nothing
        cout << "failure" << endl;
    }
    return;
}
void Graph::size()
{
    cout << "number of vertices is " << vertexNum << endl;
    return;
}

// helper functions
void Graph::sort()
{
    int i{};
    int j{};
    int tmp{};
    for (i = edgesNum; i >= 0; i--)
    {
        for (j = edgesNum; j > edgesNum - i; j--)
        {
            if (edges[j].weight > edges[j - 1].weight)
            {
                tmp = edges[j].weight;
                edges[j].weight = edges[j - 1].weight;
                edges[j - 1].weight = tmp;
            }
        }
    }
    i = 0;

    // print the edges to check if it's sorted properly
    while (i < edgesNum)
    {
        cout << edges[i].weight << " ";
        i++;
    }
    cout << endl;
    return;
}

void Graph::unionSets(int a, int b)
{
    int rootA = findParent(a);
    int rootB = findParent(b);
    if (rootA != rootB)
    {
        parent[rootA] = rootB;
    }
    else
    {
        return;
    }
}

int Graph::findParent(int n) // return wether a vertax is in the graph
{
    if (parent[n] != n)
    {
        return findParent(parent[n]);
    }
    else
    {
        return n;
    }
};

void Graph::extract()
{
    // extract all the edges from dataSet to vector edges
    // modify edgesNum while extracting
    return;
}

void Graph::printDataSet()
{
    Researcher *pTrav = dataSet;
    int i{};
    int edgesNum{};
    while (pTrav != nullptr)
    {
        edgesNum = pTrav->num;
        cout << "vertex: " << pTrav->vertexName << ":";
        for (i = 0; i < edgesNum; i++)
        {
            cout << pTrav->collabRecord[i].name << "/w:" << pTrav->collabRecord[i].weight << " ";
        }
        pTrav = pTrav->next;
        cout << endl;
    }
    return;
}

Graph::~Graph()
{
    // deallocate all the collaboration datas;
    Researcher *pTrav = dataSet;
    Researcher *pTmp = nullptr;

    while (pTrav != nullptr)
    {
        pTmp = pTrav->next;
        delete pTrav;
        pTrav = pTmp;
    }
    return;
}

Researcher::Researcher(int a, int b, int w)
{
    vertexName = a;
    collabRecord[0].name = b;
    collabRecord[0].weight = w;
}