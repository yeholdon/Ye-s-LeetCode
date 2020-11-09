#pragma once
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
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
            update(root->left, root, l);
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

