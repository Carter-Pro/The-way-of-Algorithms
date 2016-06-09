// hash
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
     int N;
     cin >> N;
     vector<int> v = {1, 2, 4, 5, 7, 10, 11, 15};
//    int value;
     map<int, int> m;
//    while (cin >> value) {
//        v.push_back(value);
//    }
     for (int i = 0; i < (int)v.size(); i++)
          m[v[i]] = i;
     for (int i = 0; i < (int)v.size(); i++) {
          auto iter = m.find(N - v[i]);
          if (iter != m.end()) {
               cout << v[i] << " " << v[iter->second] << endl;
          }
     }
     return 0;
}
