#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k) {
        // mp存所有的前缀和
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int& x:nums)
        {
            pre += x;
            // 查询之前有没有pre - k = pre ，查到了就加上次数
            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};  