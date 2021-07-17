#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    1. 中心拓展
    2. 动态规划
    3. **Manacher 算法**
*/
class Solution1 {
public:
    int countSubstrings(string s) {
        int num = 0;
        int n = s.size(); 
        for(int i=0;i<n;i++)//遍历回文中心点
        {
            for(int j=0;j<=1;j++)//j=0,中心是一个点，j=1,中心是两个点
            {
                int l = i;
                int r = i+j;
                while(l>=0 && r<n && s[l--]==s[r++])num++;
            }
        }
        return num;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        // 动态规划
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (j - i == 1)
                    dp[i][j] = (s[i] == s[j])? 1 : 0;
                else if (i == j)
                    dp[i][j] = 1;
                else
                {
                    if (dp[i+1][j-1])
                        dp[i][j] = (s[i] == s[j])?1:0;
                    else dp[i][j] = 0;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

class Solution3 {
};