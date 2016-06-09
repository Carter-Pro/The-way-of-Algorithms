//  TMOP 1.3练习2：字符的所有组合

#include <iostream>
#include <string>
using namespace std;

// 位图的思维
void calcAllCombination1(string &str) {
     if(str.empty())
          return ;
     int len = (int)str.length();
     int n = 1 << len;
     for(int i = 1; i < n; i++)    //从 1 循环到 2^len -1
     {
          for(int j = 0; j < len; j++)
          {
               int temp = i;
               if(temp & (1 << j))   //对应位上为1，则输出对应的字符
               {
                    cout << str[j];
               }
          }
          cout << endl;
     }
}
// 递归题目分析： 字符串的组合与排列不同，当交换字符串中的两个字符时，
// 虽然能得到两个不同的排列，但却是一个组合。比如ab和ba是两个排列，
// 但是一个组合。 假设输入n个字符，则这n个字符能构成长度为1的组
// 合、长度为2的组合、......、长度为n的组合。在求n个字符组成长度
// 为m的组合的时候，与字符串全排列的求解思想类似，我们可以把这n个字
// 符分为两个部分：第一个字符和剩余的其他所有的n-1个字符。这个时候可以
// 分为两种情况：

// 1. 如果组合里包含第一个字符，则从所有剩余n-1个字符里选取m-1个字符；
// 2. 如果组合里不包含第一个字符，则下一步在剩余的n-1个字符选取m个字符。
// 也就是说，我们可以把求n个字符组成长度为m的组合问题分解成两个子问题，
// 分别求n-1个字符串长度为m-1的组合，以及求n-1个字符的长度为m的组合。
// 这两个子问题都可以用递归方式解决.

void calcAllCombination2(string &str, int from, int num, string &result) {
     // 如果剩余子串中没有 num 个元素肯定是不行的
     if (from + num > (int) str.size())
          return;
     // 已经取完了
     if (num == 0) {
          for (auto e : result)
               cout << e;
          cout << endl;
          return;
     }
     result.push_back(str[from]);
     calcAllCombination2(str, from+1, num-1, result);

     result.pop_back();
     calcAllCombination2(str, from+1, num, result);

}
void combination(string &str) {
     if (str.empty())
          return;
     int size = (int)str.length();
     string result;
     for (int i = 1; i <= size; ++i)
          calcAllCombination2(str, 0, i, result);
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);
     string str1 = str;
     cout << "---------bit map----------" << endl;
     calcAllCombination1(str);
     cout << "--------recursion---------" << endl;
     string str2 = str;
     combination(str);

     return 0;
}
