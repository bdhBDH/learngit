#include <iostream>
#include <vector>
using namespace std;

class Solution{
    vector<int> vec;
    vector<int> rank;
public:
    Solution()
    {}
    ~Solution(){}
    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vec[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x)
    {
        if (x == vec[x])
            return x;
        else return find(vec[x]);
    }
    void unite(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return;
        if (rank[fx] < rank[fy])
            vec[fx] = fy;
        else 
        {
            vec[fy] = fx;
            if (rank[fx] == rank[fy])
            {
                rank[fx]++;
            }
        }
    }
};