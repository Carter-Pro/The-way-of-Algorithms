#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int manacher(const string &str) {
     // constracte special string
     string s;
     for(int i = 0; i < (int)str.size(); i++){
          s.push_back('#');
          s.push_back(str[i]);
     }
     s.push_back('#');

     // use j to quickly get the value of i
     int n = (int) s.size();
     int i;
     int mx = 0;
     int id = 0;
     vector<int> p(n, 1);
     for (i = 1; i < n; i++) {
          if (mx > i) {
               p[i] = min(p[2*id - i], mx - i);
          } else {
               p[i] = 1;
          }

          while (s[i + p[i]] == s[i - p[i]]) {
               p[i]++;
          }

          if (p[i] + i > mx) {
               mx = p[i] + i;
               id = i;
          }
     }

     int maxValue = *max_element(p.begin(), p.end()) - 1;
     return maxValue;
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     int max = manacher(str);
     cout << max << endl;
     return 0;
}
