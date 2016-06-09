#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &str) {
     if (str.empty()) {
          return true;
     }
     auto start = str.begin();
     auto end = str.end() - 1;

     while (start < end) {
          if (*start == *end) {
               ++start;
               --end;
          } else {
               return false;
          }
     }
     return true;
}

int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     if (isPalindrome(str)) {
          cout << "true" << endl;
     } else {
          cout << "false" << endl;
     }
     return 0;
}
