#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int su, vector<vector<bool>>& dp)
    {
        if (board[i][j] != word[su]) return false;
        if (su == word.size()-1) return true; 
        bool l = false, r = false, up = false, down = false;
        dp[i][j] = true;
        if (i >= 1 && !dp[i-1][j]) up = dfs(board, word, i-1, j, su+1, dp);
        if (j >= 1 && !dp[i][j-1]) l = dfs(board, word, i, j-1, su+1, dp);
        if (i < board.size()-1 && !dp[i+1][j]) down = dfs(board, word, i+1, j, su+1, dp);
        if (j < board[0].size()-1 && !dp[i][j+1]) r = dfs(board, word, i, j+1, su+1, dp); 
        dp[i][j] = false;
        return l || r || up || down;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> dp(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0, dp)) return true;
            }
        }
        return false;
    }
};