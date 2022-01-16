#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/search-insert-position/
*
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        find(nums, target, start, end);
        return nums[start] < target ? start + 1 : start;
    }

protected:
    void find(vector<int>& nums, int target, int& start, int& end) {
        if (start >= end) {
            return;
        }
        int mid = (end - start) / 2 + start;
        if (nums[mid] == target) {
            start = mid;
            return;
        }
        else {
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            find(nums, target, start, end);
        }
    }
};

int main()
{
    Solution test;
    vector<int> a{ 1,3,5,6 };
    cout << test.searchInsert(a, 5) << ": input 5\n";
    cout << test.searchInsert(a, 2) << ": input 2\n";
    cout << test.searchInsert(a, 7) << ": input 7\n";
}