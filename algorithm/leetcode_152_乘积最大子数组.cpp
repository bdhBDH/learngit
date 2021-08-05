/*
	152. 乘积最大子数组
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //存最大 和 最小
        int n = nums.size();
        vector<int>f(n,0);
        vector<int>g(n,0);
        f[0] = g[0] =nums[0];
        int ans_min = INT_MAX;
        int ans_max = nums[0];
        for(int i = 1;i<n;i++)
        {
           f[i] = min(nums[i],f[i-1]*nums[i]);
           f[i] = min(f[i],g[i-1]*nums[i]);

           g[i] = max(nums[i],g[i-1]*nums[i]);
           g[i] = max(g[i],f[i-1]*nums[i]);
           ans_max = max(ans_max,g[i]);

        }
        return ans_max;
    }
};