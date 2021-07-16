#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
		vector<int> vec;
		queue<TreeNode*> que;
		int k_size = 0;
		que.push(root);
		while (!que.empty())
		{
			k = que.size();
			while (k--)
			{
				root = que.front();
				que.pop();
				if (k == 0) vec.push_back(root->val);
				if (root->left) que.push(root->left);
				if (root->right) que.push(root->right);
			}
		}
		return vec;
    }
};