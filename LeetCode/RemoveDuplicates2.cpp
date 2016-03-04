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
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[j] == nums[i])
            {
                count++;
                if (count < 2)
                    nums[++j] = nums[i];
            }
            else
            {
                nums[++j] = nums[i];
                count = 0;
            }
        }
        return j + 1;
    }
};