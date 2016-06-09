// quick select
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int median3(vector<int> &v, int left, int right) {
     int mid = (left + right) / 2;

     if (v[left] > v[mid])
          swap(v[left], v[mid]);

     if (v[left] > v[right])
          swap(v[left], v[right]);

     if (v[mid] > v[right])
          swap(v[mid], v[right]);

     swap(v[left+1], v[mid]);
     return left+1;
}


int quickPartition(vector<int> &v, int left, int right) {
     // int pivot = median3(v, left, right);
     // int i = left+1;
     int pivot = left;
     int i = left;
     int j = right + 1;

     while (true) {
          while (v[++i] < v[pivot])
               if (i == right)
                    break;
          while (v[pivot] < v[--j])
               if (j == left)
                    break;
          if (i >= j)
               break;
          swap(v[i], v[j]);
     }
     swap(v[pivot], v[j]);
     return j;
}
int randomPartition(vector<int> &v, int left, int right) {
     int x = rand() % (right - left) + left;
     swap(v[left], v[x]);
     return quickPartition(v, left, right);
}
void quickSelect(vector<int> &v, int k, int left, int right) {
     if (left >= right) {
          std::sort(v.begin(), v.begin() + k);
          return;
     }

     // int p = quickPartition(v, left, right);
     int p = randomPartition(v, left, right);
     if (k <= p)
          quickSelect(v, k, left, p-1);
     else
          quickSelect(v, k, p+1, right);
}

int main(int argc, char *argv[])
{
     vector<int> v;
     int N, k;
     cout << "input N:";
     cin >> N;
     cout << "input k:";
     cin >> k;

     for (int i = 0; i < N; i++)
          v.push_back( std::rand() % N + 1 );
     for (int i = 0; i < N; i++)
          cout << v[i] << " ";
     cout << endl;
     quickSelect(v, k, 0, N-1);
     for (int i = 0; i < N; i++)
          cout << v[i] << " ";
     cout << endl;
     return 0;
}
