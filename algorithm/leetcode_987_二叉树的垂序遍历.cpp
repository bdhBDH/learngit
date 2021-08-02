/*
	987. 二叉树的垂序遍历
	2021/7/31
*/

class Solution {
public:
map<int,map<int,multiset<int>>>hash;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>res;
        if(root == NULL) return res;
        dfs(root , 0, 0);
        for(auto &[col, m]: hash)
        {
            vector<int>tmp;
            for(auto &[row , s]:m)
            {
                vector<int>t(s.begin(),s.end());
                for(auto & x:t)
                {
                    tmp.push_back(x);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
    void dfs(TreeNode* root, int row ,int line)
    {
        if(root == NULL) return ;
        hash[row][line].insert(root->val);
        dfs(root->left,row-1,line+1);
        dfs(root->right,row+1,line+1);
    }
};