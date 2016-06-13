#include <iostream>
#include <vector>
#include <limits>

using namespace std;
int get(vector<int> &p, int n) {
    
     vector<int> dp(n+1, 0);
    
     for (int j = 1; j <= n; j++) {
          int q = std::numeric_limits<int>::min();
          for (int i = 1; i <=j; i++) {
               if (i < (int)p.size())
                    q = max(q, p[i] + dp[j-i]);
               else
                    q = max(q, dp[i] + dp[j-i]);
          }
          dp[j] = q;
     }
     return dp[n];
}
int main(int argc, char *argv[]) {
     std::vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
     int n;
     cin >> n;
    
     int max = get(p, n);
     cout << max << endl;
     return 0;
}
