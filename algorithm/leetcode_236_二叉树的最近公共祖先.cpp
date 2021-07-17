#include <iostream>
#include <vector>
using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q) return root;
        TreeNode* node1 = dfs(root->left, p, q);
        TreeNode* node2 = dfs(root->right, p, q);
        if (node1 != nullptr && node2 != nullptr)
            return root;
        else if (node1 == nullptr)
            return node2;
        else if (node2 == nullptr)
            return node1;
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = dfs(root, p, q);
        return node;
    }
};