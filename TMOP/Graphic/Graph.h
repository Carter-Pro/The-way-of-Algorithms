#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>


class Graph
{
private:
     int n;
     std::vector<std::vector<int> > g;
public:
     Graph(int n);
     void Insert(int x, int y, int w);
     std::vector<int> getNeighbors(int node);
     int size();
     void Print();
};


#endif /* GRAPH_H */

