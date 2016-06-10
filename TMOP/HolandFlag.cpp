#include <iostream>
#include <vector>
#include <random>
using namespace std;

void hollandFlag(vector<int> &v) {
     int begin = 0;
     int current = 0;
     int end = (int) v.size() - 1;

     while (current <= end) {
          int value = v[current];

          if (value == 0) {
               swap(v[current++], v[begin++]);
          } else if (value == 1) {
               current++;
          } else {
               swap(v[current], v[end--]);
          }
     }
}
int main(int argc, char *argv[])
{
     std::random_device rd;
     std::default_random_engine random(rd());
     std::uniform_int_distribution<> u(0,2);
     vector<int> v;
     for (int i = 0; i < 20; i++)
          v.push_back(u(random));

     hollandFlag(v);

     for (auto e : v)
          cout << e << " ";
     cout << endl;
     return 0;
}
