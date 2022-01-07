#include <iostream>
#include<vector>
#include <map>
#include<unordered_map>
using namespace std;

/*
* https://leetcode-cn.com/problems/palindrome-number/
* Given an integer x, return true if x is palindrome integer.
* An integer is a palindrome when it reads the same backward as forward.
* For example, 121 is a palindrome while 123 is not.
*/

class Solution {
public:
    /*
    * false situation: 1. x<0; 2.left!=right
    * foreach loop:
    left = x/length  (length is x's digits)
    right = x%10
    x = (x%length) % 10
    length = length / 100
    */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        // calculate length
        int length;
        for (length = 1; (x / length) >= 10; length *= 10);
        //printf("%d length is %d\n", x, length);
        
        int left, right;
        while (x > 0) {
            left = x / length;
            right = x % 10;
            if (left != right) {
                return false;
            }
            x = (x % length) / 10;
            length /= 100;
        }
        return true;
    }
};

int main() {
    Solution test;
    printf("%d : %d\n", 10, test.isPalindrome(10));
    printf("%d : %d\n", 101, test.isPalindrome(101));
    printf("%d : %d\n", 1001, test.isPalindrome(1001));
    printf("%d : %d\n", 3, test.isPalindrome(3));
    printf("%d : %d\n", 313, test.isPalindrome(313));
}