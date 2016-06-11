#include <iostream>
#include <vector>

using namespace std;

void smallChange(vector<int> &money, vector<int> &numbers, int sum, int x, int &count) {
     if (sum <= 0 || x >= (int)money.size())
          return;
     if (sum == money[x]) {
          // numbers[x]++;
          // for (int i = 0; i < (int)money.size(); i++) {
          //      //if (numbers[i] == 0)
          //      //      continue;

          //      if (i == 0)
          //           cout << money[i] << "*" << numbers[i];
          //      else
          //           cout << " + " << money[i] << "*" << numbers[i];
          // }
          // cout << endl;
          // numbers[x]--;
          count++;
     }

     numbers[x]++;
     smallChange(money, numbers, sum - money[x], x, count);

     numbers[x]--;
     smallChange(money, numbers, sum, x+1, count);
}

int main(int argc, char *argv[])
{
     int sum;
     cin >> sum;
     vector<int> money = {100, 50, 20, 10, 5, 2, 1};
     vector<int> numbers((int)money.size(), 0);
     int count = 0;
     smallChange(money, numbers, sum, 0, count);
     cout << count << endl;
     return 0;
}
