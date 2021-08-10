/*
	860.柠檬水找零
*/class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0;i<bills.size();i++)
        {
            if(bills[i] == 5) five++;
            if(bills[i] == 10) five--,ten++;
            if(bills[i] == 20) 
            {
                if(ten) ten--,five--;
                else five-=3;
            }
             if(five<0) return false;
        }
    return true; 
    }
};