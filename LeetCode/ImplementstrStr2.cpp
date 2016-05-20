#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void getNext(string &target, int next[]) {
     int k = -1;
     int j = 0;
     next[0] = -1;
     int len = (int) target.size();
     while (j < len - 1) {
          if (k == -1 || target[k] == target[j]) {
               ++j;
               ++k;
               if (target[k] == target[j])
                    next[j] = next[k];
               else
                    next[j] = k;
          } else {
               k = next[k];
          }
     }
}

int main(int argc, char *argv[])
{
     string source;
     string target;

     getline(cin, source);
     getline(cin, target);
     if (target.empty()) {
          cout << "0" << "\n";
          return 0;
     }
     int i = 0;
     int j = 0;
     int len1 = source.size();
     int len2 = target.size();

     int *next = (int*)malloc(len2 * sizeof(int));
     //memset(next, 0, len2 * sizeof(int));
     getNext(target, next);
     while (i < len1 && j < len2) {

          if (j == -1 || source[i] == target[j]) {
               ++i;
               ++j;
          } else {
               j = next[j];
          }
     }

     if (j == len2) {
         
          return i - j;
     }


     return -1;
}
