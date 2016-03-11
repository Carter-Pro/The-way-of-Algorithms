#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (target == nums[mid])
                return mid;
            if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

        }
        return -1;
    }
};
int main(void)
{
    Solution test;

    int array[] = {4,5,6,7,0,1,2};
    vector<int> nums(array, array + 2);

    int result;
    for (int i = 0; i < 8; ++i) {
        result = test.search(nums, i);
        if (result == -1)
            cout << "null" << endl;
        else
            cout << result << endl;
    }
    return 0;
}