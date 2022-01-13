#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/remove-element/
*
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int size = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val) {
                k++;
            }
            else {
                size++;
                nums[i - k] = nums[i];
            }
        }
        return size;
    }

    void validate(vector<int> nums, int val) {
        int k = removeElement(nums, val); // Calls your implementation

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
    vector<int> a{ 3,2,2,3 };
    test.validate(a, 3);
    vector<int> b{ 0,1,2,2,3,0,4,2 };
    test.validate(b, 2);
}