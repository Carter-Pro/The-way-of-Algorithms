//每个坐标容纳的水量都是边界较小的那个的高度减去该坐标
#include <iostream>
#include <vector>
using namespace std;
int TrappingRainWater(vector<int> &height) {
     int trap = 0;
     int left = 0;
     int secHight = 0;
     int right = (int)height.size() - 1;

     while (left < right) {
          if (height[left] < height[right]) {
               secHight = max(secHight, height[left]);
               trap += (secHight - height[left]);
                    left++;
          } else {
               secHight = max(secHight, height[right]);
               trap += (secHight - height[right]);
               right--;
          }
     }

     return trap;
}
int main(int argc, char *argv[])
{
     vector<int> height;
     int input;
     while (cin >> input)
          height.push_back(input);
     int trap = TrappingRainWater(height);
     cout << trap << endl;
     return 0;
}
