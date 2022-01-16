#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/maximum-subarray/
*
*/
class Solution {
public:
    /*
    dynamic programming
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max = nums[0];
        int lastSubMax = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // max greater than zero is better
            if (lastSubMax > 0) {
                lastSubMax = lastSubMax + nums[i];
            }
            else {
                lastSubMax = nums[i];
            }
            max = max < lastSubMax ? lastSubMax : max;
        }        
        return max;
    }
};

int main() {
    Solution test;
    vector<int> a{ -2,1,-3,4,-1,2,1,-5,4 };
    cout << test.maxSubArray(a) << ":6\n";
    vector<int> b{ 1 };
    cout << test.maxSubArray(b) << ":1\n";
    vector<int> c{ 5,4,-1,7,8 };
    cout << test.maxSubArray(c) << ":23\n";
}