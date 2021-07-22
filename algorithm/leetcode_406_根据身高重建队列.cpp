#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& p1, const vector<int>& p2){
            return (p1[0] > p2[0])||(p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& person:people)
        {
            ans.insert(ans.begin()+person[1], person);
        }
        return ans;
    }
};