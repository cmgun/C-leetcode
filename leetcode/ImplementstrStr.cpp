#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/remove-element/
*
*/
class Solution {
public:
    // KMP
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j]) {
                // not match
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                // match all
                return i - j + 1;
            }
        }
        return -1;
    }

protected:
    void getNext(vector<int>& next, string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
            {// different perfix
                j = next[j-1];
            }
            if (s[i] == s[j])
            {// same perfix
                j++;
            }
            next[i] = j;
        }
    }
};

int main()
{
    Solution test;
    cout << test.strStr("hello", "ll") << "\n";
    cout << test.strStr("aaaaa", "bba") << "\n";
    cout << test.strStr("", "") << "\n";
    cout << test.strStr("mississippi", "issip") << "\n";
}