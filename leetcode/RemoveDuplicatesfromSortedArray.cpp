#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
*
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int k = 0;
        int size = 1;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (pre == nums[i]) {
                k++;
            }
            else {
                pre = nums[i];
                // back to k
                nums[i - k] = nums[i];
                size++;
            }
        }
        return size;
    }

    void validate(vector<int> nums) {
        int k = removeDuplicates(nums); // Calls your implementation

        cout << "k is:" << k << "\n";

        cout << "result is:";
        for (int i = 0; i < k; i++) {
            cout << nums[i] << ",";
        }
        cout << "\n";
    }
};

int main()
{
    Solution test;
    vector<int> a{ 1, 1, 2 };
    test.validate(a);
    vector<int> b{ 0,0,1,1,1,2,2,3,3,4 };
    test.validate(b);
}