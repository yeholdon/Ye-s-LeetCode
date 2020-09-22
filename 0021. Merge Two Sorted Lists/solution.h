#pragma once

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
class Solution {
public:
    // 常规解法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy1, dummy2, dummy3;
        dummy1.next = l1;
        dummy2.next = l2;
        ListNode* p1 = &dummy1, * p2 = &dummy2, * p3 = &dummy3;
        while (p1->next != nullptr && p2->next != nullptr)
        {
            if (p1->next->val < p2->next->val)
            {
                p3->next = new ListNode(p1->next->val);
                p1 = p1->next;
            }
            else
            {
                p3->next = new ListNode(p2->next->val);
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if (p1->next == nullptr)
        {
            p3->next = p2->next;
        }
        if (p2->next == nullptr)
        {
            p3->next = p1->next;
        }
        return dummy3.next;

    }
    // 简洁解法，使用递归
    // ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    //     if (!a || b && a->val > b->val) swap(a, b);
    //     if (a) a->next = mergeTwoLists(a->next, b);
    //     return a;
    // }
};