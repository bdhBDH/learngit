#include <iostream>
using namespace std;
#include <vector>

/*
 // f[i][0]: 手上持有股票的最大收益
 // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
 // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
*/
class Solution{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() == 0) return 0;
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(3, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i][0], dp[i-1][2] - prices[i]);
			dp[i][1] = dp[i-1][0]+prices[i];
			dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
		}
		return max(dp[n-1][1], dp[n-1][2]);
	}
};
