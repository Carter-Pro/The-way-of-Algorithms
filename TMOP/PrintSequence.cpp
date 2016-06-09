// 序列打印
#include <iostream>
#include <string>

using namespace std;

void combination(string &str, string &result, int from, int num) {
     if (from + num > (int)str.size())
          return;
     if (num == 0) {
          cout << "(";
          for (auto it = result.begin(); it != result.end(); ++it) {
               if (it+1 == result.end())
                    cout << *it;
               else
                    cout << *it << ",";
          }
          cout << "),";
     } else {
          result.push_back(str[from]);
          combination(str, result, from+1, num-1);

          result.pop_back();
          combination(str, result, from+1, num);
     }
}
void printSequence1(string &str) {
     string result;
     for (int i = 1; i < (int)str.size(); ++i) {
          combination(str, result, 0, i);
          cout << endl;
     }
}
int main(int argc, char *argv[])
{
     //string str = "abcdefghijklmnopqrstuvwxyz";
     string str = "abc";
     printSequence1(str);
     return 0;
}
