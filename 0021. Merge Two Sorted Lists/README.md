# 思路(C++)

## 思路一

常规解法，创建归并后的链表。然后按照归并的规则依次将节点添加到结果链表中。

## 思路二(递归)

递归方法及其简洁。

```c++
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a || b && a->val > b->val) swap(a, b);
    if (a) a->next = mergeTwoLists(a->next, b);
    return a;
}
```
