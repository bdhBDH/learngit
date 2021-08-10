/*
	2021/8/4 每日一题
	611. 有效三角形的个数
*/
/*
	solution 1 -双指针
*/
class Solution {
public:
int res  = 0;
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int k = n-1;k>=2;k--)
        {
            for(int j = k-1, i = 0;j>i;)
            {
                if(nums[i]+nums[j]>nums[k])
                {
                    res += j -i ;
                    j--;
                }
                else i++;
            }
        }
        return res;
    }
    
};
/*
	solution 2 -二分查找
*/
class Solution {
public:
int res  = 0;
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n-2;i++)
        {
            for(int j = i+1;j<n-1;j++)
            {
                int x = nums[i]+nums[j]; 
                int ans = j ;
                if(nums[j+1] < x)
                    ans = find_x(nums, j+1,n-1,x);
                res += (ans - j );
               // cout<<i<<" "<<j<<" "<<ans<<" "<<(ans - j )<<endl;
            }
        }
        return res;
    }
    int find_x(vector<int>& nums, int l ,int r ,int x)
    {
        while(l<r)
        {
            int mid = l + r + 1>>1;
            if(nums[mid] < x) l = mid;
            else r =  mid -1;
        }
        return l;
    }
};
