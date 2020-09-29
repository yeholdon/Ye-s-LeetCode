```cpp
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr)    return true;
    if (root->left == nullptr)  return isValidBST(root->right) && root->right->val > root->val;
    else if (root->right == nullptr)    return isValidBST(root->left) && root->left->val < root->val;
    else    return isValidBST(root->left) && isValidBST(root->right) && root->left->val < root->val&& root->right->val > root->val;
```


```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTReal(root, nullptr, nullptr);
    }

    bool isValidBSTReal(TreeNode* root, TreeNode* lo, TreeNode* hi)
    {
        if (root == nullptr)    return true;//走到当前节点为空了，还没决定出是false，就返回true
        // if (root->left == nullptr && root->right == nullptr)    return true;// 由于要证真需要两棵子树的结果，而并非简单的左右子节点的结果，所以应该通过hi和lo来判断
        // 从反证的角度来确定递归边界。任意递归层次，只要出现满足是false就返回false，无需再往下递归。
        if (hi != nullptr && root->val >= hi->val)   return false;
        if (lo != nullptr && root->val <= lo->val)   return false;
        
        return isValidBSTReal(root->left, lo, root) && isValidBSTReal(root->right, root, hi);
    }
};


```

