#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> temp(digits.size(), 0);
        int sum = 0;
        int one = 1;
        for (int i = digits.size() - 1; i >= 0 ; --i) {
            sum = digits[i] + one;
            one = sum / 10;
            temp[i] = sum % 10;
        }
        if (one > 0)
            temp.insert(temp.begin(), one);
        return temp;
    }
};
int main(void)
{
    Solution test;

    int array[] = {9,9};
    vector<int> nums(array, array + 2);

    vector<int> result;
    result = test.plusOne(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}