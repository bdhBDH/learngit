#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> temp;
        stack<int> index;
        vector<int> ans(n, 0);
        temp.push(temperatures[n-1]);
        index.push(n-1);
        ans[n-1] = 0;
        int i = n-2;
        while (i >= 0)
        {
            while (!temp.empty())
            {
                if (temperatures[i] >= temp.top())
                {
                    temp.pop();index.pop();
                }
                else
                {
                    ans[i] = index.top() - i;
                    break;
                }
            }
            if (temp.empty()) ans[i] = 0;
            temp.push(temperatures[i]);
            index.push(i);
            i--;
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {73,74,75,71,69,72,76,73};
    Solution p;
    vector<int> ans = p.dailyTemperatures(a);
    return 0;
}