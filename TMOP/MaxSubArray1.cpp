// brute forces
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Get(vector<int> &v, decltype(v.begin()) begin) {
     vector<int> n(begin, v.end());

     for (int i = 0; i < n.size(); i++)
          if (i != 0)
               n[i]+=n[i-1];

     return *std::max_element(n.begin(), n.end());
}

int getValue(vector<int> &v) {
     vector<int> maxValue;

     for (auto it = v.begin(); it != v.end(); ++it) {
          maxValue.push_back(Get(v, it));
     }

     return *std::max_element(maxValue.begin(), maxValue.end());

}
int main(int argc, char *argv[])
{
     vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
     int c = getValue(v);
     cout << c << endl;
     return 0;
}
