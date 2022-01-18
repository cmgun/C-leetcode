#include <iostream>

using namespace std;

/**
* https://leetcode-cn.com/problems/length-of-last-word/
*
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s.at(i) == ' ')
        {
            i--;
        }
        int count = 0;
        while (i >= 0 && s.at(i) != ' ')
        {
            i--;
            count++;
        }
        return count;
    }
};

int main() {
    Solution test;
    cout << test.lengthOfLastWord("Hello World") << ":5\n";
    cout << test.lengthOfLastWord("   fly me   to   the moon  ") << ":4\n";
    cout << test.lengthOfLastWord("luffy is still joyboy") << ":6\n";
}