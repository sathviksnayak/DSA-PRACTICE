class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> case1(nums.begin(),nums.end()-1);
        vector<int> case2(nums.begin()+1,nums.end());

        return max(robx(case1),robx(case2));
    }
    int robx(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        int n1=nums[0];
        int cur,n2=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            cur =max(n2,n1+nums[i]);
            n1=n2;
            n2=cur;
        }return n2;

    }
};