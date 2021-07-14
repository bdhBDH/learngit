#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    时间复杂度：O(n*nlogn);
    空间复杂度：O(n)
*/
class Solution {
public:
    static constexpr int mod = 1'000'000'007;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum = 0;
        vector<int> res(nums1);
        sort(res.begin(), res.end());
        int maxn = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff)% mod;
            // lower_bound : 找到第一个大于或者等于nums[i]的数值
            // j 为索引位置
            int j = lower_bound(res.begin(), res.end(), nums2[i]) - res.begin();
            if (j < n)
            {
                maxn = max(maxn, diff - (res[j] - nums2[i]));
            }
            if (j > 0)
            {
                maxn = max(maxn, diff - (nums2[i] - res[j-1]));
            }
        }
        return (sum - maxn + mod)%mod;
    }
};