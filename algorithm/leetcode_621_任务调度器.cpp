#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

/*
    用了排序原理
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> res(26, 0);
        for (char& num:tasks)
        {
            res[num-'A']++;
        }
        sort(res.begin(), res.end(), [](int& x, int& y){return x>y;});
        int cnt = 1;
        while (cnt < res.size() && res[cnt] == res[0]) cnt++;
        return max(tasks.size(), (res[0]-1)*(n+1)+cnt);
    }
};