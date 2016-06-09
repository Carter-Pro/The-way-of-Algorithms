// print the longest palindrome substrings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void manacher(string &str, vector<int> &v) {
     string s;
     for (auto e : str) {
          s += '#';
          s += e;
     }
     s += '#';

     int id = 0;
     int mx = 0;
     int n = (int) s.size();
     for (int i = 1; i < n; i++) {
          if (mx > i) {
               v[i] = min(v[id*2 - i], mx - i);
          }

          while (s[i+v[i]] == s[i-v[i]]) {
               v[i]++;
          }

          if (mx < v[i] + i) {
               mx = v[i] + i;
               id = i;
          }
     }
}

void print(string &s, vector<int> &v) {
     int n = (int)v.size();
     vector<int> p(n, 0);
     for (int i = 0; i < n; i++) {
          for (int j = i - (v[i]/2 - 1); j < i + (v[i]/2 - 1); j++) {
               if (p[j] < i)
                    p[j] = i;
          }
     }

     int sign = 0;
     for (int i = 0; i < n; i++) {
          if (sign != p[i]) {
               cout << endl;
               sign = i;
          }
          cout << s[i];
     }
     cout << endl;
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     vector<int> v((int)str.size(), 1);
     manacher(str, v);
     print(str, v);
     return 0;
}
