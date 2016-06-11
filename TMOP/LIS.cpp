#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void find(string &str, vector<int> &v) {
     v[0] = 1;
     for (int i = 1; i < (int)str.size(); i++) {
          for (int j = 0; j < i; j ++) {
               if (str[j] < str[i])
                    v[i] = max(v[j]+1, v[i]);
          }
     }
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     vector<int> v((int)str.size(), 0);
     find(str, v);
     auto max = std::max_element(v.begin(), v.end());
     cout << *max << endl;
     return 0;
}
