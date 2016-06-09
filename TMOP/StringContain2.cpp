// 1. quick-sort, 时间复杂度O(mlogm + nlogn) + O(m+n)
// 2. counting sort, 时间复杂度降低到O(m+n)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool stringContain(string &a, string &b) {
     sort(a.begin(), a.end());
     sort(b.begin(), b.end());

     int pa = 0;
     int pb = 0;

     while (pa < a.size() && pb < b.size()) {
          if (a[pa] < b[pb])
               pa++;
          else if (a[pa] == b[pb])
               pb++;
          else
               return false;
     }
     if (pa == a.size() && pb != b.size())
          return false;
     else
          return true;
}
int main(int argc, char *argv[])
{
     string a;
     string b;

     for (int i = 0; i < 2; i++) {
          getline(cin, a);
          getline(cin, b);
          bool contained = stringContain(a, b);
          if (contained)
               cout << "True" << endl;
          else
               cout << "False" << endl;
     }
     return 0;
}
