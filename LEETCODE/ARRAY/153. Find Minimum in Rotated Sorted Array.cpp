class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
// 1 2 3 4 5   5 1 2 3 4   5 4 3 2 1   4 5 1 2 3
        while(l<r){
            int mid=l+(r-l)/2;
          if(nums[mid]>nums[r]) l=mid+1;
          else r=mid;
        }
        return nums[l];
    }
};