#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &str) {
     if (str.empty()) {
          return true;
     }
     int size = (int)str.size();
     int m = ((size >> 1) -1) >= 0 ? (size >> 1) - 1 : 0;
     auto start = str.begin() + m;
     auto end = str.end() - m - 1;

     while (start >= str.begin()) {
          if (*start != *end) {
               return false;
          }
          --start;
          ++end;
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
