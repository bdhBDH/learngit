#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <algorithm>
#include <unordered_map>


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map1; 
        for(string &str:strs){
            string key = str;
            sort(key.begin(), key.end());
            map1[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it=map1.begin(); it != map1.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};