#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
* https://leetcode-cn.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 1; i <= strs[0].size(); i++)
        {
            string sub = strs[0].substr(0, i);
            if (sub.empty()) {
                break;
            }
            bool match = true;
            for (int j = 1; j < strs.size(); j++)
            {
                string sub1 = strs[j].substr(0, i);
                if (sub.compare(sub1) != 0) {
                    match = false;
                    break;
                }
            }
            if (!match) {
                break;
            }
            result = sub;
        }
        return result;
    }
};

class Solution2 {
public:
    // find shortest and longest one, compare them
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
        {
            return "";
        }
        const auto p = minmax_element(strs.begin(), strs.end());
        for (int i = 0; i < p.first->size(); ++i) 
        {
            if (p.first->at(i) != p.second->at(i))
            {
                return p.first->substr(0, i);
            }
        }
        return *p.first;
    }
};

int main() {
    Solution test;
    vector<string> t1 = { "abab","aba","abc" };
    string r1 = test.longestCommonPrefix(t1);
    cout << r1 << "\n";

    vector<string> t2 = { "a","aba","abc" };
    string r2 = test.longestCommonPrefix(t2);
    cout << r2 << "\n";
}
