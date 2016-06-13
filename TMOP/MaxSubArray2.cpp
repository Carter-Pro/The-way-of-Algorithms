// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getValue(const vector<int> &v) {
     int size = (int)v.size();
     vector<int> dp(size, 0);
     dp[0] = v[0];

     for (int i = 1; i < size; ++i) {
          dp[i] = std::max(dp[i-1] + v[i], v[i]);
     }

     return *std::max_element(dp.begin(), dp.end());
}

int main(int argc, char *argv[])
{
     vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
     int c = getValue(v);
     cout << c << endl;
     return 0;
}
