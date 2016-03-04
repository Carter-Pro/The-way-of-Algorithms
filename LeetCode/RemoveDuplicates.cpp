#include <iostream>
#include <vector>
using namespace std;

class RemoveElement {
public:
    int removeelement(vector<int>& nums, int value) {
        int i = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == value)
                continue;

            nums[j] = nums[i];
            j++;
        }
        return j;
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