#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size()||s.size()==0) return ans;
        
        vector<int>need(128);
        vector<int>windows(128);
        for(char a:p) need[a]++;
        for(int i=0;i<p.size()-1;i++) windows[s[i]]++;
        int l=0,r=p.size()-1;//窗口是[l,r]
        while(r<s.size())
        {
            windows[s[r++]]++;
            if(windows==need) ans.push_back(l);
            windows[s[l++]]--;
        }
        return ans;
    }
};