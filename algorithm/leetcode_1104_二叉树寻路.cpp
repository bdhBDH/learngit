/*
	2021/7/29 每日一题
*/
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>res;
        if(label == 1) return{1};
        //先判断是哪一层
        int stage = 0;//不超过30层
        res.push_back(label);
        for(int i = 0;i<30;i++)
        {
            if(label < (1<<i))
            {
                stage = i-1;
                break;
            }
        }
        cout<<stage<<endl;
        //得到上一层的最小数 
        int min_front = (1<<(stage-1)), max_front = (1<<stage)-1;
        //cout<<min_front <<" "<<max_front<<endl;
        int ans = label;
        while(stage!=1)
        {
            ans = max_front + min_front - (ans)/2;// 两边和 - 本身 就是对称的
            res.push_back(ans);
            stage --;
            max_front = max_front = (1<<stage)-1;
            min_front = (1<<(stage-1));
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        return res;
    }
};