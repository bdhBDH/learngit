#include <iostream>
#include <vector>
using namespace std;
/*
    转化为股票买卖问题，时间复杂读为O（n）
    滑动窗口:O(n)
    空间复杂度：O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }
        int buy = nums[0];
        int maxNumber = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxNumber = max(max(maxNumber, nums[i]), nums[i] - buy);
            buy = min(buy, nums[i]);
        }
        return maxNumber;
    }
};