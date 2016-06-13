#include <iostream>
#include <vector>
#include <random>
using namespace std;

bool isOdd(int value) {
     return value % 2 != 0 ? true : false;
}
void oddEvenSort(vector<int> &v) {
     if (v.empty())
          return;
     int size = (int)v.size();
     if (size == 0)
          return;
     int left = 0;
     int right = size-1;

     while (left < right) {
          if (isOdd(v[left]))
               left++;
          else if (!isOdd(v[right]))
               right--;
          else
               std::swap(v[left++], v[right]);
     }
}

int main(int argc, char *argv[])
{
     std::random_device rd;
     std::uniform_int_distribution<int> dis(0, 20);
     vector<int> v;

     for (int i = 0; i < 10; i++)
          v.push_back(dis(rd));
     for (auto e : v)
          cout << e << " ";
     cout << endl;
     oddEvenSort(v);

     for (auto e : v)
          cout << e << " ";
     cout << endl;

     return 0;
}
