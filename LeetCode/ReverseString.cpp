#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
     string s;
     cin >> s;
     cout << s.size() << "\n";
     for (decltype(s.size()) i = 0; i < s.size() / 2; ++i){
          auto t = s[i];
          s[i] = s[s.size() - 1 - i];
          s[s.size() - 1 - i] = t;
     }
     cout << s << "\n";
     return 0;
}

