#include <iostream>
#include <stack>
using namespace std;

bool checkParenthesis(string expression) {
    stack<char> parenthesis;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            parenthesis.push(ch);
        }
        else {
            if (!parenthesis.empty()) {
                char top = parenthesis.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    parenthesis.pop();
                }
                else return false;
            }
            else return false;
        }
    }
    return (parenthesis.empty());
}//((((((

int main(){
    string expression;
    cout << "Expression (){}[]: ";
    cin >> expression;
    bool correct = checkParenthesis(expression);
    if (correct) {
        cout << "OK";
    }
    else {
        cout << "NO";
    }
    return 0;
}