/*
	455. 分发饼干
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size(), n = s.size();
        int t = 0;//饼干数量
        int i = 0;
        for(;i<m;i++)
        {
            while(t<n && s[t]<g[i] ) t++;
            if(t == n) break;
            t++;
        }
        return i;
    }
};