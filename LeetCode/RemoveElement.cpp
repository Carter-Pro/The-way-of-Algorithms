#include <iostream>
#include <vector>
using namespace std;

class RemoveElement 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int head = 0;
        int tail = nums.size() - 1;
       
        while (head <= tail)
        {
            if (nums[head] == val)
            {
                nums[head] = nums[tail];
                --tail;
            }
            else
                ++head;
        }
        return tail+ 1;
    }
};
int main(void)
{
    RemoveElement test;

    int array[] = {1, 2, 2, 3, 2, 4};
    vector<int> nums(array, array + 6);

    int result;
    result = test.removeElement(nums, 2);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}