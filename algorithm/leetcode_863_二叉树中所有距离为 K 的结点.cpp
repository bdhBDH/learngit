/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
	2021/7/28的每日一题
	向上dfs与向下dfs
	向上dfs需要记录父节点 （map<int,TreeNode*> 因为每个结点的值是唯一的）
 **/
class Solution {
public:
int dis;
map<int,TreeNode*>hash;
set<TreeNode*>vis;
vector<int>res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) return {};
        dfs(root);
        dfs1(target,0,k);
        return res;
    }
    void dfs(TreeNode* root)
    {
        if(root == NULL) return ;
        //记录子节点的父节点
        if(root->left) 
        {
            hash[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right) 
        {
            hash[root->right->val] = root;
            dfs(root->right);
        }
    }
    void dfs1(TreeNode* root ,int depth , int k)
    { 
        //判重
        if(root == NULL || vis.find(root)!=vis.end()) return;
        vis.insert(root);
        if(depth == k )
        {
            res.push_back(root->val);
            return ;
        }
 		//向下与向上递归
        dfs1(root->left,depth+1,k);
        dfs1(root->right,depth+1,k);
        dfs1(hash[root->val],depth+1,k);
    }
};