#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/house-robber/
*
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp;
        for (int i = 0; i <= nums.size(); i++) {
            dp.push_back(0);
        }
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.size()];
    }
};

int main() {
    Solution test;
    vector<int> nums{ 1,2,3,1 };
    cout << test.rob(nums) << endl;
    return 0;
}