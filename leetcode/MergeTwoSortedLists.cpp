#include <iostream>

using namespace std;

/**
* https://leetcode-cn.com/problems/merge-two-sorted-lists/
* 
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        ListNode* p;
        if (list1 != NULL && list2 == NULL) {
            return list1;
        }
        if (list1 == NULL && list2 != NULL) {
            return list2;
        }
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }

        if (list1->val > list2->val) {
            result = list2;
            list2 = list2->next;
        }
        else {
            result = list1;
            list1 = list1->next;
        }
        p = result;
        
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                p->next = list2;
                list2 = list2->next;
            }
            else
            {
                p->next = list1;
                list1 = list1->next;
            }
            p = p->next;
        }
        if (list1 != NULL) 
        {
            p->next = list1;
        }
        if (list2 != NULL)
        {
            p->next = list2;
        }
        return result;
    }

    ListNode* initList(int a[], int length) {
        ListNode* head = new ListNode(a[0]);
        ListNode* p = head;
        for (int i = 1; i < length; i++)
        {
            ListNode* c = new ListNode(a[i]);
            p->next = c;
            p = p->next;
        }
        return head;
    }

    void output(ListNode* r) {
        while (r != NULL) {
            cout << r->val << ",";
            r = r->next;
        }
    }
};

int main() {
    Solution test;
    int a[] = { 1, 2, 4 };
    ListNode* list1 = test.initList(a, 3);
    int b[] = { 1,3,4 };
    ListNode* list2 = test.initList(b, 3);
    ListNode* result = test.mergeTwoLists(list1, list2);
    test.output(result);
};
