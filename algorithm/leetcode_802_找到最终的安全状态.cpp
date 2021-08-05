/*
	802. 找到最终的安全状态
	反向图 + 拓扑排序
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //反向图
        int n = graph.size();
        vector<vector<int>>g(n);
        vector<int>d(n,0);

        for(int i = 0;i<n;i++)
        {
            for(auto &x: graph[i])
            {
                int t = x;
                g[x].push_back(i);
            }
        }
        for(int i = 0;i<n;i++)
        {
            d[i] = graph[i].size();
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(!d[i])  q.push(i);
        }
        while(q.size())
        {
            int top= q.front();
            q.pop();
            for(int i = 0;i<g[top].size();i++)
            {
                d[g[top][i]]--;
                if(d[g[top][i]]==0)
                    q.push(g[top][i]);
            }
        }
        vector<int>res;
        for(int i = 0;i<n;i++)
        {
            if(d[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};