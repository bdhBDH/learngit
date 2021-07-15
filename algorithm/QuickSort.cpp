#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int quickSort(vector<int>& nums, int l, int r)
    {
        int x = nums[l];
        int left = l;
        int right = r;
        while (left < right)
        {
            while (left < right && nums[right] > x)
            {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] < x)
            {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = x;
        return left;
    }
    void QSort(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int mid = quickSort(nums, l, r);
            QSort(nums, l, mid);
            QSort(nums, mid+1, r);
        }
    }
};