#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
     string s;
     getline(cin, s);

     transform(s.begin(), s.end(), s.begin(), ::tolower);

     auto left = s.begin();
     auto right = prev(s.end());

     while (left < right) {
          if (!std::isalnum(*left))
               left++;
          else if (!std::isalnum(*right))
               right--;
          else if (*left != * right) {
               cout << "unvalid!" << endl;
               return 0;
          } else {
               left++;
               right--;
          }
     }

     cout << "valid" << endl;
     return 0;
}


