#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void MergeSort(vector<int>& nums, int l, int r, int q)
    {
        int n = r - l + 1;
        vector<int> temp(n);
        int m = l, n = q+1;
        int i = 0;
        while (i < n)
        {
            while (m <= q && n <= r)
                temp[i++] = nums[m] > nums[n] ? nums[n++]:nums[m++];
            while (m <= q)
                temp[i++] = nums[m++];
            while (n <= r)
                temp[i++] = nums[n++];
        }
        for (int i = 0; i < n; i++)
        {
            nums[i+l] = temp[i];
        }
    }
    void Merge(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int mid = (l+r)/2;
            Merge(nums, l, mid);
            Merge(nums, mid+1, r);
            MergeSort(nums, l , r, mid);
        }
    }
};