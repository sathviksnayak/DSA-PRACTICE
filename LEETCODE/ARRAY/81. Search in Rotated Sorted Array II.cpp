class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        if(nums.size()==1){
            if(nums[0]==target) return true;
            else return false;
        }
        while(l<=r){
            mid=l+(r-l)/2;


            if(nums[mid]==target) return true;
                    if(nums[l]==nums[mid]&& nums[r]==nums[mid]){
            l++;
            r--;
            continue;
        }
            if(nums[l]<=nums[mid]){
                if(target<nums[mid]&&target>=nums[l]) r=mid-1;
                else l=mid+1;
            }
            else if(nums[r]>=nums[mid]){
                if(target<=nums[r]&&target>nums[mid]) l=mid+1;
                else r=mid-1;
            }
        }



        return false;
        
    }
};