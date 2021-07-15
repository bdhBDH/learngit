#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void insertSort(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            int x = nums[i];
            for (int j = i-1; j >= 0; j--)
            {
                if (x < nums[j])
                {
                    nums[j+1] = nums[j];
                }
                else
                {
                    nums[j+1] = x;
                    break;
                }
            }
        }
    }
};