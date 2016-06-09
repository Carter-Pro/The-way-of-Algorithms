// 下排序 next_permutation
#include <string>
#include <iostream>

using namespace std;

bool calcAllPermutation(string &str, int num) {
     // 二找，一交换，一翻转

     // Step 1
     int i;
     for (i = num - 2; (i >= 0) && (str[i] >= str[i+1]); --i);

     // already find all permutation
     if (i < 0)
          return false;

     // Step 2
     int k = 0;
     for (k = num -1; (k > i) && (str[k] <= str[i]); --k);

     // Step 3
     swap(str[i], str[k]);

     // Step 4
     reverse(str.begin() + i + 1, str.begin() + num);

     return true;
}
int main(int argc, char *argv[])
{
     string str;
     getline(cin, str);

     do {
          cout << str << endl;
     } while(calcAllPermutation(str, (int)str.length()));
     return 0;
}
