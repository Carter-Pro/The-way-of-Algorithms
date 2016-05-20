// recursion way
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool isOperator(string &token) {
     return token.size() == 1 && string("+-*/").find(token) != string::npos;
}

int evalRPN(vector<string>& tokens) {
     int x, y;
     string token = tokens.back();
     tokens.pop_back();

     if (isOperator(token)) {
          y = evalRPN(tokens);
          x = evalRPN(tokens);

          if      (token[0] == '+') x += y;
          else if (token[0] == '-') x -= y;
          else if (token[0] == '*') x *= y;
          else if (token[0] == '/') x /= y;
     } else {
          x = stoi(token);
     }
     return x;
}
int main(int argc, char *argv[])
{
     vector<string> tokens;
     string in;
     while (cin >> in) {
          tokens.push_back(in);
     }

     cout << evalRPN(tokens) << endl;
     return 0;
}
