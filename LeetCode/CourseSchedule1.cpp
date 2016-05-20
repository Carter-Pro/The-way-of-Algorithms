#include <iostream>
#include <queue>
#include <utility>

class Solution {
public:
     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
          queue<int> q;
          vector<vector<int> > adj(numCourses, vector<int>(0));
          int degree[numCourses] = {0};

          for (auto e : prerequisites) {
               adj[e.first].push_back(e.second);
               degree[e.second]++;
          }

          for (int i = 0; i < numCourses; i++) {
               if (degree[i] == 0)
                    q.push(i);
          }

          int cur;
          int count = 0;
          while (!q.empty()) {
               cur = q.front();
               q.pop();
               count++;

               for (auto e : adj[cur]) {
                    degree[e]--;
                    if (degree[e] == 0)
                         q.push(e);
               }
          }
          return count < numCourses ? false : true;
     }
};
