//use deep instead of stack, reduce space O(n) to O(1)
//It's possible that the number of '(' is larger than the number of ')', therefor scan 2 times
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
     string s;

     getline(cin, s);

     int start = -1;
     int n = 0;
     int size = (int)s.size();

     int deep = 0;

     //first
     for (int i = 0; i < size; i++) {
          if (s[i] == '(') {
               ++deep;
          } else {
               if (deep == 0) {
                    start = i;
               } else {
                    --deep;
                    if (deep == 0)
                         n = max(n, i - start);
               }
          }
     }
     //second

     deep = 0;
     start = size;

     for (int i = size - 1; i >= 0; --i) {
          if (s[i] == ')') {
               ++deep;
          } else {
               if (deep == 0)
                    start = i;
               else {
                    --deep;
                    if (deep == 0)
                         n = max(n, start - i);
               }
          }
     }
     cout << n << endl;
     return 0;
}
