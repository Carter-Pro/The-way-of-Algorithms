#include <iostream>
#include <vector>

class CountingSort
{
public:
     void static countingSort(std::vector<int> &array, std::vector<int> &output, int N, int K) {

          // elements bigger than 0
          std::vector<int> count(K, 0);

          for (auto e : array)
               count[e]++;
          for (int i = 1; i <= K; i++)
               count[i] += count[i-1];

          for (int i = N-1; i >=0; i--) {
               output[count[array[i]]-1] = array[i];
               count[array[i]]--;
          }
     }
};



