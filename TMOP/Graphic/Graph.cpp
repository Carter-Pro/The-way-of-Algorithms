#include <iostream>
#include <limits>
#include "Graph.h"
#define MAX std::numeric_limits<int>::max()

Graph::Graph(int n) {
     this->n = n;
     for (int i = 0; i <= n; i++) {
          std::vector<int> v(n+1, MAX);
          g.push_back(v);
     }
     for (int i = 0; i <= n; i++) {
          g[i][i] = 0;
     }
}

void Graph::Insert(int x, int y, int w) {
     g[x][y] = w;
}


std::vector<int> Graph::getNeighbors(int node) {
     return g[node];
}

void Graph::Print() {
     for (auto v : g) {
          for (auto e : v)
               std::cout << e << " ";
          std::cout << std::endl;
     }
}

int Graph::size() {
     return n;
}
