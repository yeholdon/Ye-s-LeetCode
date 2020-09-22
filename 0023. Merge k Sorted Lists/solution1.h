class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode*t1, *t2;
        
        if(l1->val > l2->val){
            ListNode* tmp = l2;
            l2 = l1;
            l1 = tmp;
        }
        t1 = l1;
        t2 = l2;
        
        while(t1->next){
            if(t1->next->val>t2->val){
                //point to t2
                ListNode* tmp = t1->next;
                t1->next = t2;
                //swap t1 and t2
                t2 = tmp;
                t1 = t1->next;
            }
            else t1 = t1->next;
        }
        if(t2)
            t1->next = t2;
        return l1;
        
    }
    
    ListNode* merge(vector<ListNode*>& lists, int m, int n){
        if(m == n){
            return lists[m];
        }
        if(n-m == 1){
            return mergeTwoLists(lists[m], lists[n]);
        }
   
        return mergeTwoLists(merge(lists, m, m + (n - m)/2), merge(lists, m + (n - m)/2 + 1, n));
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n == 0) return {};
        if(n == 1) return lists[0];
        
        ListNode* result = merge(lists, 0, n-1);
        
        return result;
    }
    
};