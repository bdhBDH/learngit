#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int& num:nums)
            ++umap[num];
        vector<pair<int, int>> vec;
        for (auto& mp:umap)
        {
            vec.push_back(mp);
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> pa1, pair<int, int> pa2){return pa1.second < pa2.second;});
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(vec[i].first);
        }
        return res;
    }
};

int main()
{
    vector<int> res = {-1, -1};
    int k = 1;
    Solution p;
    vector<int> ans;
    ans = p.topKFrequent(res, k);
    return 0;
}