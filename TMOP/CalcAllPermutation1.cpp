// 递归
// 注意重复元素
#include <string>
#include <iostream>

using namespace std;
bool isDuplicate(const string &str, int from, int to) {
     while (from < to)
     {
          if (str[from] == str[to])
               return true;
          from++;
     }
     return false;
}

void calcAllPermutation(string &str, int from, int to) {
     if (from == to) {
          for (auto e : str)
               cout << e;
          cout << endl;
     } else {
          for (int i = from; i <= to; i++) {
           if (isDuplicate(str, from, i))
               continue;
               std::swap(str[i], str[from]);
               calcAllPermutation(str, from+1, to);
               std::swap(str[i], str[from]);
          }
     }
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);
     calcAllPermutation(str, 0, (int)str.length()-1);
     return 0;
}
