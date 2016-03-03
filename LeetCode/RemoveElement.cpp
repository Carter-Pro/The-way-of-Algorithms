#include <iostream>
#include <vector>
using namespace std;

class RemoveElement 
{
public:
    int removeelement(vector<int>& nums, int value) 
    {
        int i = nums.size() - 1;
        int j = 0;
        while (j <= i)
        {
            
        }
    }
};
int main(void)
{
    RemoveElement test;

    int array[] = {1, 2, 2, 3, 2, 4};
    vector<int> nums(array, array + 6);

    int result;
    result = test.removeelement(nums, 2);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}