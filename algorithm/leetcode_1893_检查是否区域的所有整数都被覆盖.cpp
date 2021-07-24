#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> dp(right-left+1, 0);
        for (const vector<int>& re:ranges)
        {
            if (re[1] < left) continue;
            else if (re[0] > right) continue;
            else
                for (int i = re[0]; i <= re[1]; i++)
                    if (i >= left && i <= right) dp[i-left] = 1;
        }
        for (int i = 0; i < right-left + 1; i++)
            if (dp[i] == 0) return false;
        return true;
    }
};