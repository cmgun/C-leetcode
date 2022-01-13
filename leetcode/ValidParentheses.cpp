#include <string>
#include <iostream>
#include <stack>

using namespace std;

/*
* https://leetcode-cn.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++)
        {
            char a = s.at(i);
            switch (a)
            {
            case '(':
            case '{':
            case '[':
            {
                stack.push(a);
                break;
            }
            case ')':
            {
                if (stack.empty()) {
                    return false;
                }
                char b = stack.top();
                if (b != '(') {
                    return false;
                }
                else {
                    stack.pop();
                }
                break;
            }
            case '}':
            {
                if (stack.empty()) {
                    return false;
                }
                char b = stack.top();
                if (b != '{') {
                    return false;
                }
                else {
                    stack.pop();
                }
                break;
            }
            case ']':
            {
                if (stack.empty()) {
                    return false;
                }
                char b = stack.top();
                if (b != '[') {
                    return false;
                }
                else {
                    stack.pop();
                }
                break;
            }
            default:
                break;
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};

int main() {
    Solution test;
    cout << test.isValid("()") << "\n";
    cout << test.isValid("()[]{}") << "\n";
    cout << test.isValid("(]") << "\n";
    cout << test.isValid("([)]") << "\n";
    //"{[]}"
    cout << test.isValid("{[]}") << "\n";
}