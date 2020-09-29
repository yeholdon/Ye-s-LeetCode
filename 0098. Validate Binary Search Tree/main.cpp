
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTReal(root, nullptr, nullptr);
    }

    bool isValidBSTReal(TreeNode* root, TreeNode* lo, TreeNode* hi)
    {
        if (root == nullptr)    return true;
        if (root->left == nullptr && root->right == nullptr)    return true;
        // �ӷ�֤�ĽǶ���ȷ���ݹ�߽硣����ݹ��Σ�ֻҪ����������false�ͷ���false�����������µݹ顣
        if (hi != nullptr && root->val > hi->val)   return false;
        if (lo != nullptr && root->val < lo->val)   return false;
        
        return isValidBSTReal(root->left, lo, root) && isValidBSTReal(root->right, root, hi);
    }
};

