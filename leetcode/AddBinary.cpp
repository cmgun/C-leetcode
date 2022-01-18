#include <iostream>

using namespace std;

/**
* https://leetcode-cn.com/problems/add-binary/
*
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        char cin = '0';
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int aLen = a.size();
        int bLen = b.size();
        if (aLen < bLen) {
            a.insert(aLen, bLen - aLen, '0');
        }
        else
        {
            b.insert(bLen, aLen - bLen, '0');
        }
        int len = max(aLen, bLen);
        for (int i = 0; i < len; i++)
        {
            if (cin == '0') {
                if (a[i] == '0' && b[i] == '0') {
                    result += '0';
                }
                else if (a[i] == '1' && b[i] == '1') {
                    cin = '1';
                    result += '0';
                }
                else {
                    result += '1';
                }
            }
            else {
                if (a[i] == '0' && b[i] == '0') {
                    result += '1';
                    cin = '0';
                }
                else if (a[i] == '1' && b[i] == '1') {
                    result += '1';
                }
                else {
                    result += '0';
                }
            }
        }
        if (cin == '1') {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution test;
    cout << test.addBinary("100", "110010") << ":110110 \n";
    cout << test.addBinary("11", "1") << ":100 \n";
    cout << test.addBinary("1010", "1011") << ":10101 \n";
}