#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
     if (n == 0)
          return 0;
     vector<int> v(n+1, 0);
     v[0] = 1;
     v[1] = 1;

     for (int i = 2; i <= n; ++i)
          v[i] = v[i-1] + v[i-2];

     return v[n];
}
int main(int argc, char *argv[])
{
     int n;
     cin >> n;

     int value = climbStairs(n);

     cout << value << endl;
     return 0;
}

