#include <iostream>
#include <string>
using namespace std;

// 暴力求解, O(m * n)
int main(int argc, char *argv[])
{
     string source;
     string target;

     getline(cin, source);
     getline(cin, target);

     int p1 = 0;
     int p2, p3;
     int len1 = source.size();
     int len2 = target.size();
     while (p1 < len1) {

          for (p2 = 0, p3 = p1; p2 < len2 && source[p3] == target[p2]; ++p2, ++p3);

          if (p2 == len2) {
               cout << p1 << endl;
               return 0;
          }
          else
               ++p1;
     }

     cout << "-1" << endl;
     return 0;
}
