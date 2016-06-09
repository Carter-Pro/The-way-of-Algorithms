//brute force
#include <iostream>
#include <string>
using namespace std;

bool stringContain(string &a, string &b) {
     int i, j;
     for (i = 0; i < b.size(); i++) {
          char c = b[i];
          for (j = 0; j < a.size(); j++) {
               if (c == a[j])
                    break;
          }
          if (j == a.size())
               return false;
     }
     return true;
}
int main(int argc, char *argv[])
{
     string a;
     string b;
     getline(cin, a);
     getline(cin, b);

     bool contained = stringContain(a, b);
     cout << contained << endl;
     return 0;
}
