#include <iostream>
#include <vector>
using namespace std;

class SOlution{
public:
    void selectSort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size() -1; i++)
        {
            int min = i;
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] < nums[min]) min = j;
            }
            swap(nums[min], nums[min]);
        }
    }
};