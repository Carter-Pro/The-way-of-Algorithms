//以i和栈顶元素为边间（不包括在内），计算这个区间内的最大矩形面积
//最后以-1和新添加的0为边界
//其实，分析的是以a[i]为最小值的矩形的面积，因此，需要左边第一个比a[i]小的和右边第一个比a[i]小的值
//因此用栈来记录左边的第一个值！！！
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int largestRectangleArea(vector<int> &heights) {
     heights.push_back(0);
     stack<int> s;
     int answer = 0;
     int temp;
     for (int i = 0; i < (int)heights.size(); ) {
          if (s.empty() || heights[i] > heights[s.top()]) {
               s.push(i);
               ++i;
          } else {
               temp = s.top();
               s.pop();
               answer = max(answer, heights[temp] * (s.empty() ? i : i - s.top() - 1));
          }
     }
     return answer;
}
int main(int argc, char *argv[])
{
     int input;
     vector<int> heights;
     while (cin >> input) {
          heights.push_back(input);
     }

     int max = largestRectangleArea(heights);
     cout << max << endl;
     return 0;
}
