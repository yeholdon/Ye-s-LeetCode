/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/*	
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int carry = 0;
         ListNode *dummyHead = new ListNode(0), *p = dummyHead;
         ListNode *c1 = l1, *c2 = l2;
         while(c1 != NULL || c2 != NULL) {
             int sum = (c1 ? c1->val : 0) + (c2 ? c2->val : 0) + carry;
             carry = sum / 10;
             p->next = new ListNode(sum % 10);
             p = p->next;
             if(c1 != NULL) c1 = c1->next;
             if(c2 != NULL) c2 = c2->next;
         }
         if(carry > 0) p->next = new ListNode(carry);
        
         return dummyHead->next;
     }
*/     
    // ʡ�����ֲ�����,��Լ��Ľⷨ 
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) { // ���ⵥ���������λ��λ������ 
            if (l1) extra += l1->val, l1 = l1->next;
            if (l2) extra += l2->val, l2 = l2->next;
            p->next = new ListNode(extra % 10);
            extra /= 10;
            p = p->next;
        }
        return preHead.next;
    }
};


