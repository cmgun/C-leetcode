#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode-cn.com/problems/remove-comments/
*
*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string>::iterator it = source.begin();
        string status = "str";
        string blockOutStr = "";
        while (it != source.end()) {
            string str = *it;
            int pos = str.find("//");
            int blockPos = str.find("/*");
            if (pos != string::npos && (pos < blockPos || blockPos == -1) && status == "str") {
                if (pos > 0) {
                    *it = str.substr(0, pos);
                }
                else {
                    it = source.erase(it);
                }
                continue;
            }
            if (blockPos != string::npos && status == "str") {
                status = "blockStart";
            }
            if (status == "block" || status == "blockStart") {
                int blockEndPos = -1;
                int i = status == "blockStart" ? blockPos + 2 : 0;
                int len = str.size() - 1;
                for (; i < len; i++) {
                    if (str[i] == '*' && str[i + 1] == '/') {
                        blockEndPos = i;
                        break;
                    }
                }
                if (blockPos > 0 && status == "blockStart") {
                    blockOutStr = str.substr(0, blockPos);
                } 
                if (blockEndPos != string::npos) {
                    status = "str";
                    if (blockEndPos != str.size() - 2) {
                        blockOutStr += str.substr(blockEndPos + 2);
                    }
                    if (blockOutStr != "") {
                        *it = blockOutStr;
                        blockOutStr = "";
                        continue;
                    }
                }
                if (status == "blockStart") {
                    status = "block";
                }
                it = source.erase(it);
            }
            else {
                it++;
            }
        }
        return source;
    }
};

int main() {
    Solution test;
    vector<string> source{ "/*Test program */", "int main()", "{ ", "  // variable declaration "
        , "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */"
        , "a = b + c;", "}" };
    vector<string> source1{ "a/*comment", "line", "more_comment*/b" };
    vector<string> source2{ "struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};" };
    vector<string> source3{ "void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}" };
    vector<string> source4{ "main() {", "  Node* p;", "  /* declare a Node", "  /*float f = 2.0", "   p->val = f;", "   /**/", "   p->val = 1;", "   //*/ cout << success;*/", "}", " " };
    vector<string> source5{ "a//*b//*c","blank","d/*/e*//f" };
    vector<string> source6{ "a/*/b//*c", "blank", "d//*e/*/f" };
    vector<string> source7{ "main() { ", "  int a = 1; /* Its comments here ", "", "  ", "  */ return 0;", "} " };
    vector<string> result = test.removeComments(source7);
    vector<string>::iterator it = result.begin();
    while (it != result.end()) {
        cout << *it << endl;
        it++;
    }
    return 0;
}