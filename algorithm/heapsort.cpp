#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void heapSort(vector<int>& nums, int i, int len)
    {
        int temp = nums[i];
        for (int k = 2*i+1; k < len; k=2*k+1)
        {
            if (k+1 < len && nums[k] < nums[k+1]) k++;
            if (nums[k] > temp)
            {
                nums[i] = nums[k];
                i = k;
            }
            else break;
        }
        nums[i] = temp;
    }
    void Hsort(vector<int>& nums)
    {
        // build the max_tree
        int n = nums.size();
        for (int i = n / 2; i >= 0; i--)
        {
            heapSort(nums, i, n);
        }
        for (int j = n-1; j > 0; j--)
        {
            swap(nums[0], nums[j]);
            heapSort(nums, 0, j);
        }
    }
};