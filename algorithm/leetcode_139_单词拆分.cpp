#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && wordDictSet.find(s.substr(i, j-i)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }

            }   
        }
        return dp[s.size()];
    }
};