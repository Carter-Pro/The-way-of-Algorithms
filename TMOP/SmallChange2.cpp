// dp
#include <iostream>
#include <vector>

using namespace std;

int charge(int value, vector<int> money) {
     int size = (int) money.size();
     vector<vector<int>> dp(size, vector<int>(value + 1, 1));

     for (int i = 1; i < size; i++) {
          for (int j = 1; j < value+1; j++) {
               if (j >= money[i])
                    dp[i][j] = dp[i][j - money[i]] + dp[i - 1][j];
               else
                    dp[i][j] = dp[i - 1][j];
          }
     }

     return dp[size-1][value];
}
int main(int argc, char *argv[])
{
     vector<int> money = {1, 2, 5, 10, 20, 50, 100};
     int value;
     cin >> value;

     int c = charge(value, money);
     cout << c << endl;
     return 0;
}


