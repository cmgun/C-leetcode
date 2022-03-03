#include <iostream>

using namespace std;

/**
* https://leetcode-cn.com/problems/power-of-three
*
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main() {
	Solution test;
    cout << test.isPowerOfThree(27) << endl;
    return 0;
}