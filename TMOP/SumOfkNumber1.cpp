#include <iostream>
#include <vector>
#include <list>
using namespace std;
list<int> list1;
void SumOfkNumber(int sum, int n) {
     if (sum <= 0 || n <= 0)
          return;

     if (sum == n) {
          //list1.reverse();
          cout << n;
          for (auto e : list1)
               cout << " + " << e;
          cout << endl;
          //list1.reverse();
     }

     list1.push_front(n);
     SumOfkNumber(sum - n, n - 1);
     list1.pop_front();
     SumOfkNumber(sum, n - 1);
}
int main(int argc, char *argv[])
{
     int n, sum;
     cin >> n;
     cin >> sum;

     SumOfkNumber(sum, n);
     return 0;
}
