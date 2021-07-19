#include <iostream>
#include <vector>
using namespace std;
/*
    卡特兰数字
*/

class Solution {
public:
    int numTrees(int n) {
        /*
            Cn+1 = Cn * 2(2n-1)/n+2
        */
        long long pre = 1;
        for (int i = 1; i < n; i++)
        {
            pre = pre * 2 * (2*i+1)/(i+2);
        }
        return (int)pre;
    }
};