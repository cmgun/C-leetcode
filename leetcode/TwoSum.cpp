#include <iostream>
#include<vector>
#include <map>
#include<unordered_map>
using namespace std;

/*
* https://leetcode-cn.com/problems/two-sum/
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* You can return the answer in any order.
*/


class Solution {
public:
    // uing map to store targe-nums[i]
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            int sub = target - key;
            if (map.find(sub) == map.end()) {
                // can't find target-key
                map[key] = i;
            } else {
                // find target-key
                result.push_back(map[sub]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution test;
    vector<int> a{ 3,2,4 };
    vector<int> result = test.twoSum(a, 6);
    for (auto i = result.begin(); i < result.end(); i++) {
        cout <<  + *i << " ";
    }
}