/*
	1005. K 次取反后最大化的数组和
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res =0;
        while(k--)
        {
            sort(nums.begin(),nums.end());
            nums[0] = -nums[0];
        }
        for(auto &x:nums)
        {
            res+=x;
        }
        return res;
    }
};