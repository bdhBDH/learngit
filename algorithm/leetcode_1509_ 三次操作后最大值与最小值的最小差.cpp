class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(),nums.end());
        //0 1 5 10 14  缩短 min和max的距离 改变 max 或者 min 只有三个数会被改变
        //看剩下的数 差的最大最小值 n - 3 ;
        int n = nums.size();
        //int len = n - 4;
        // cout<<len<<endl;
        int ans = INT_MAX;
        for(int i = 0;i<4;i++)
        {
            ans = min(ans , nums[i+n-4]-nums[i]);
        }
        return ans;
    }
};