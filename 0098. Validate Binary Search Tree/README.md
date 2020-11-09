# 思路(C++)

### 方法一(递归)

通常，按照直觉，会想当然的按照二叉查找树的性质，认为只要满足当前节点值比左节点大，右节点小即可。然后不断地利用递归，确定好边界和递归式即可。但是实际上，这种方式是不对的，因为实际上，这个性质只是二叉查找树的必要条件，而非充分。

```cpp
bool isValidBST(TreeNode* root) {
	if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr)    return true;
        if (root->left == nullptr)  return isValidBST(root->right) && root->right->val > root->val;
        else if (root->right == nullptr)    return isValidBST(root->left) && root->left->val < root->val;
        else    return isValidBST(root->left) && isValidBST(root->right) && root->left->val < root->val&& root->right->val > root->val;
}
```

充要条件是对任意有左右子树非空的节点，当前节点的值要处在左右子树所有节点值的中间，而非仅仅是左右孩子的值之间。或者换句话说，当前节点的值需要在其前驱节点值和后继节点值之间。因此，递归式就需要有能够传递前驱和后继节点的方式，体现在递归方程中就是增加两个参数，分别表示前驱和后继节点。

但是接下来还有一个问题，就是递归是从根节点开始的，但是根节点的前驱后继节点我们并不知道，只要当往下层递归时，可以确定上层的节点为下层的前驱或者后继。这就需要从反面来论证了，既然无法知道前缀和后继来证明当前二叉树是BST（因为需要两个子树都为BST才能是BST），而如果我们要知道当前二叉树不是BST的话，只要知道一边的关系不满足即可，无需两边都知道，这个可以作为递归边界之一。另外，还有一个递归边界就是当前二叉树为空树时，认为是BST。这样递归边界返回true和false的情况都有，逻辑上也没有漏洞，可以大胆地实现它，尽管比较难以理解。


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

### 方法二(用栈模拟递归，迭代法)

递归调用实际上是用系统栈实现的，因此，递归的方法通常都可以转化为用栈来实现，栈存放的是每一层递归的状态。这里其实就算把方法一用栈来实现。

```cpp
class Solution {
public:
    stack<TreeNode*> st, lo, hi;
    bool isValidBST(TreeNode* root) {
        update(root, nullptr, nullptr);
        TreeNode* l = nullptr, * h = nullptr;
        while (!st.empty())
        {
            root = st.top();
            l = lo.top();
            h = hi.top();
            st.pop();
            lo.pop();
            hi.pop();

            if (root == nullptr)
            {
                continue;
            }
            int val = root->val;
            if (l != nullptr && val <= l->val)  return false;
            if (h != nullptr && val >= h->val)  return false;
            update(root->right, root, h);
            update(root->left, l, root);
        }
        return true;
    }
    void update(TreeNode* root, TreeNode* l, TreeNode* h)
    {
        st.push(root);
        lo.push(l);
        hi.push(h);
    }
};

```

### 方法三(中序遍历)

中序遍历二叉查找树的结果应该是有序的，利用这一性质来判断。

```cpp
class Solution {
public:
    long long inVal = INT64_MIN; // 这个要注意，如果BST是只有一个值为INT_MIN的节点的话，这里设为INT_MIN就会有错
    bool ans = true;
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    void inOrder(TreeNode* root)
    {
        if (root == nullptr) return;
        inOrder(root->left);
        if (root->val <= inVal)  ans = false;
        inVal = root->val;
        inOrder(root->right);
    }

};
```

