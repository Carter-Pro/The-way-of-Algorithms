#include <iostream>
#include <string>
using namespace std;


void reverseString(string &str, int from, int to) {
     char c;
     while (from < to) {
          c = str[from];
          str[from++] = str[to];
          str[to--] = c;
     }
}

void leftRotateString(string &str) {
     int size = (int) str.size();
     int from = 0;
     int to = 0;

     for (int i = 0; i < size; i++) {
          if (str[i] == ' ') {
               reverseString(str, from, to-1);
               from = to + 1;
               to = from;
          } else {
               ++to;
          }
     }
     reverseString(str, from, to-1);
     reverseString(str, 0, size-1);
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     leftRotateString(str);
     cout << str << endl;
     return 0;
}
