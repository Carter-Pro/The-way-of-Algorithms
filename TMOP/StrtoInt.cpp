#include <iostream>
#include <string>
using namespace std;

// 需要考虑一些细节：
// 1. 输入是否为空
// 2. 如果第一个字符为'-'，则应该为负数
// 3. 输入不能包含不是数字的字符
// 4. 不能太长，防止溢出
int StrtoInt(const string &str) {
     static const int MAX_INT = (int)((unsigned)~0 >> 1);
     static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
     unsigned int n = 0;
     auto e = str.begin();
     if (str.empty())
          return 0;

     while (std::isspace(*e)) {
          e++;
     }
     int sign = 1;
     if (*e == '+' || *e == '-') {
          if (*e == '-')
               sign = 0;
          ++e;
     }

     while (std::isdigit(*e)) {
          int c = *e - '0';

          if (sign > 0 
     }
}

int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);
     int value = StrtoInt(str);
     cout << value << endl;
     return 0;
}
