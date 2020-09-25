#pragma once

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct cmp
{
    bool operator () (ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode, *p = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        int lists_num = lists.size();
        for (size_t i = 0; i < lists_num; i++)
        {
            if (lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty())
        {
            p->next = pq.top();
            if (pq.top()->next != nullptr)  pq.push(pq.top()->next);
            pq.pop();
            p = p->next;
        }
        return dummy->next;
    }
};