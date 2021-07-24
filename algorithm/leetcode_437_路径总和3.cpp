#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
    题目有两种解法：
        1. easy:先要dfs根节点所有向下的路径
        2. 然后要dfs左右节点所有向下的路径
        3. 一次，就是递归中套了一层递归

    Solution2:
        先要把所有节点都改为前缀和形式
        然后定义hash——set
        在做一次dfs既可以
*/

class Solution1 {
public:
    int count = 0;
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        dfs(root, targetSum);            //以root为起始点查找路径
        pathSum(root->left, targetSum);  //左子树递归
        pathSum(root->right, targetSum); //右子树递归
        return count;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum -= root->val;
        if (sum == 0) //注意不要return,因为不要求到叶节点结束,所以一条路径下面还可能有另一条
            count++;  //如果找到了一个路径全局变量就+1
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};

// 代码2可能有部分错误，读者可以自行修正
class Solution2 {
    unordered_set<int> se;
    int count = 0;
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        sum1(root, 0);
        dfs(root, targetSum);
        return count;
    }

    void dfs(TreeNode* node, int targetSum)
    {
        if (node == nullptr) return;
        if (se.find(node->val - targetSum) != se.end()) count++;
        
        se.insert(node->val);
        dfs(node->left, targetSum);
        dfs(node->right, targetSum);
        se.erase(node->val);
    }
    void sum1(TreeNode *root, int sum)
    {
        if (root == nullptr) return;

        root->val += sum;
        sum1(root->left, root->val);
        sum1(root->right, root->val);
    }
};