#include "Graph.h"
#include <iostream>
#include <limits>
#include <stack>
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
void dijkstra(Graph& g, int start, vector<int>& path, vector<int>& pre) {
     path = g.getNeighbors(start);
     pre = vector<int>(g.size()+1, start);

     vector<int> neighbors = g.getNeighbors(start);

     for (int i = 1; i <= g.size(); i++) {
          if (i == start)
               continue;
          int min = getMin(neighbors);
          neighbors = g.getNeighbors(min);
          for (int i = 1; i <= g.size(); i++) {
               if (neighbors[i] != MAX) {
                    //path[i] = std::min(path[i], neighbors[i] + path[min]);
                    if (path[i] > neighbors[i] + path[min]) {
                         path[i] = neighbors[i] + path[min];
                         pre[i] = min;
                    }
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
     
     vector<int> path;
     vector<int> pre;
     int start = 1;
     dijkstra(g, start, path, pre);
     for (int i = 1; i <= g.size(); i++) {
          if (i == start)
               continue;
          cout << i << ": ";
          if (path[i] != MAX)
               cout << path[i] << " ";
          else
               cout << "+∞" << " ";
          stack<int> s;
          int index = i;
          while (index != pre[index]) {
               s.push(index);
               index = pre[index];
          }

          cout << index << "->";
          while (!s.empty()) {
               int e = s.top();
               s.pop();
               if (!s.empty())
                    cout << e << "->";
               else
                    cout << e;
          }
          cout << endl;
     }
     return 0;
}
