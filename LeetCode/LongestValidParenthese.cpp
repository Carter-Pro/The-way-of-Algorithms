#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
     string s;

     getline(cin, s);

     stack<int> st;
     int start = -1;
     int n = 0;
     int size = (int)s.size();

     for (int i = 0 ; i < size; i++) {
          if (s[i] == '(') {
               st.push(i);
          } else {
               if (st.empty())
                    start = i;
               else {
                    st.pop();
                    //每次i-st.top() 都是目前匹配的长度，每次匹配了都和最大长度比较
                    //空栈是一种特殊情况，空栈了没有栈顶元素，只能和start比较
                    if (st.empty())
                         n = max(n, i - start);
                    else
                         n = max(n, i - st.top());
               }
          }
     }
     cout << n << endl;
     return 0;
}
