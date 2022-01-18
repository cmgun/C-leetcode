#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/plus-one/
*
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i]++;
				return digits;
			}
		}
		digits.insert(digits.begin(), 1);
		return digits;
    }

	void print(vector<int> a) {
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i] << ",";
		}
		cout << "\n";
	}
};

int main() {
	Solution test;
	vector<int> a{ 1,2,3 };
	test.print(test.plusOne(a));
	vector<int> b{ 4,3,2,1 };
	test.print(test.plusOne(b));
	vector<int> c{ 9 };
	test.print(test.plusOne(c));
}