class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];


        int n1=nums[0],n2=max(nums[0],nums[1]),cur;

        for(int i=2;i<nums.size();i++){
            cur=max(n2,n1+nums[i]);
            n1=n2;
            n2=cur;
        }
     return n2;   
    }
};