/*
	870.优势洗牌
	贪心：
	
*/class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>st;
        for(auto &x:nums1) st.insert(x);
        vector<int>res;
        int n = nums1.size();
        for(int i = 0;i<n;i++)
        {
            auto it = st.upper_bound(nums2[i]);
            if(it == st.end()) 
            {
                it = st.begin();
            }
            res.push_back(*it);
            st.erase(it);
        }
        return res;
    }
};