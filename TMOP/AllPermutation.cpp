// TMOP 1.3 习题1: 字典序的所有排列
#include <iostream>
#include <string>
using namespace std;

void allPermutation(string &str, string &s, int from, int size, int len) {

     if (len == size) {
          for (auto e : s)
               cout << e;
          cout << endl;
     } else {
          for (int i = 0; i < size; i++) {
               s[from] = str[i];
               allPermutation(str, s, from+1, size, len+1);
          }
     }
}

int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);
     string s = str;
     allPermutation(str, s, 0, (int)str.length(), 0);
     return 0;
}
