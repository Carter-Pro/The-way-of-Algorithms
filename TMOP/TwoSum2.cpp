// 排序夹逼
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &v, unsigned int length, int x) {
     int lo = 0;
     int hi = length - 1;
     while (lo <= hi) {
          int mid = (lo + hi) / 2;
          if (x == v[mid])
               return mid;
          else if (x < v[mid])
               hi = mid - 1;
          else
               lo = mid + 1;
     }
     return -1;
}
// binary search
void find1(vector<int> &v, unsigned int length, int sum) {
     for (int i = 0; i < length; i++) {
          int p = binarySearch(v, length, sum - v[i]);
          if (p != -1) {
               cout << "method1: ";
               cout << v[i] << " " << v[p] << endl;
               return;
          }
     }
}

void find2(vector<int> &v, unsigned int length, int sum) {
     int begin = 0;
     int end = length - 1;
     while (begin < end) {
          int x = v[begin] + v[end];
          if (x == sum) {
               cout << "method2: ";
               cout << v[begin] << " " << v[end] << endl;
               return;
          } else if (x < sum)
               ++begin;
          else
               --end;
     }
}

void twoSum(vector<int> &v, unsigned int length, int sum) {
     //find1
     find1(v, length, sum);
     //find2
     find2(v, length, sum);
}

int main(int argc, char *argv[])
{
     int sum;
     cin >> sum;

     vector<int> v;
     int value;
     while (cin >> value) {
          v.push_back(value);
     }
     //sort
     std::sort(v.begin(), v.end());
     twoSum(v, (unsigned int)v.size(), sum);
     return 0;
}
