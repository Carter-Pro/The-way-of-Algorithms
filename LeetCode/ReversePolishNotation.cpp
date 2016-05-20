#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool isOperator(string &token) {
     return token.size() == 1 && string("+-*/").find(token) != string::npos;
}
int main(int argc, char *argv[])
{
     vector<string> tokens;
     string in;
     while (cin >> in) {
          tokens.push_back(in);
     }

     stack<string> st;

     for (auto e : tokens) {
          if (!isOperator(e)) {
               st.push(e);
          } else {
               int y = stoi(st.top());
               st.pop();
               int x = stoi(st.top());
               st.pop();
               if      (e[0] == '+') x += y;
               else if (e[0] == '-') x -= y;
               else if (e[0] == '*') x *= y;
               else if (e[0] == '/') x /= y;
               st.push(to_string(x));
          }
     }
     delete st;
     cout << st.top() << endl;
     return 0;
}
