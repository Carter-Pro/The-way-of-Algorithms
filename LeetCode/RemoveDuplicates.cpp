#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int j = 0;
        for (int i = 1; i < n; ++i)
            if (nums[j] != nums[i])
              nums[++j] = nums[i];
        return j + 1;
    }
};
int main(void)
{
    RemoveElement test;

    int array[] = {1, 2, 2, 2, 3, 4};
    vector<int> nums(array, array + 6);

    int result;
    result = test.removeelement(nums, 2);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}