// random quick sort
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int quickPartition(vector<int> &v, int left, int right) {
     int i = left+1;
     int j = right;

     while (true) {
          while (v[i] < v[left]) {
               if (i == right)
                    break;
               ++i;
          }
          while (v[left] < v[j]) {
               if (j == left)
                    break;
               --j;
          }
          if (i >= j)
               break;
          swap(v[i], v[j]);
     }
     swap(v[left], v[j]);
     return j;
}

int randomPartition(vector<int> &v, int left, int right) {
     int p = std::rand() % (right - left) + left;
     swap(v[left], v[p]);
     return quickPartition(v, left, right);
}
void quickSort(vector<int> &v, int left, int right) {
     if (right <= left)
          return;

     int p = quickPartition(v, left, right);
     quickSort(v, left, p-1);
     quickSort(v, p+1, right);
}

int main(int argc, char *argv[])
{
     vector<int> v;
     for(int i = 0; i < 10; i++)
          v.push_back(rand() % 10 + 1);

     quickSort(v, 0, 9);

     for (auto e : v)
          cout << e << " ";
     cout << endl;
     return 0;
}
