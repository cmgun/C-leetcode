#include <iostream>

using namespace std;

/**
* https://leetcode-cn.com/problems/sqrtx/
*
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 0;
        int right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int smallerMid = x / mid;
            int greaterMid = x / (mid + 1);
            if (x / smallerMid == smallerMid) {
                return smallerMid;
            }
            if (smallerMid > mid && greaterMid < mid + 1) {
                return mid;
            }
            if (smallerMid > mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution test;
    cout << test.mySqrt(6);
}