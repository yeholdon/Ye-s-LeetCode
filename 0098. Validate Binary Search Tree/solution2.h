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
    long long inVal = INT64_MIN;
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

