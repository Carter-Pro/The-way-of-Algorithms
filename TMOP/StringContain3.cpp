//hash
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool stringContain(string &a, string &b) {
     int hash = 0;
     //用一个整数的26位代替每个大写字符，很高级的 hash 思想
     for (int i = 0; i < a.length(); ++i) {
          hash |= (1 << (a[i] - 'A'));
          cout << "value: " << (1 << (a[i] - 'A')) << endl;
          cout << hash << endl;
     }

     for (int i = 0; i < b.length(); ++i) {
          if ((hash & (1 << (b[i] - 'A'))) == 0)
               return false;
     }
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
