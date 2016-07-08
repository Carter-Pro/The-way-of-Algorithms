#include "Graph.h"
#include <iostream>
#include <limits>
#include <set>
#include <algorithm>
#define MAX std::numeric_limits<int>::max()
using namespace std;

int getMin(const vector<int> v) {
     int min = 0;
     for (int i = 0; i < v.size();i++) {
          if (v[i] == 0)
               continue;
          if (v[i] < v[min])
               min = i;
     }
     return min;
}
void dijkstra(Graph& g, int start, vector<int>& path) {
     path = g.getNeighbors(start);
     std::set<int> s;
     s.insert(start);
     vector<int> neighbors = g.getNeighbors(start);

     for (int i = 1; i <= g.size(); i++) {
          if (i == start)
               continue;
          int min = getMin(neighbors);
          neighbors = g.getNeighbors(min);
          for (int i = 1; i <= g.size(); i++) {
               if (neighbors[i] != MAX) {
                    path[i] = std::min(path[i], neighbors[i] + path[min]);
               }
          }
     }
}
int main(int argc, char *argv[])
{
     int n, x, y, w;
     cin >> n;
     Graph g(n);
     while (cin >> x >> y >> w) {
          g.Insert(x, y, w);
     }
     //g.Print();

     vector<int> path;

     dijkstra(g, 1, path);
     for (int i = 1; i <= g.size(); i++)
          cout << path[i] << " ";
     cout << endl;
     return 0;
}
