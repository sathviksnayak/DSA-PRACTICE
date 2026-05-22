class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
       int ans=1,prev=nums[0];
       for(int i=1;i<nums.size();i++){
        if(prev<=nums[i]){
            ans++;
            prev=nums[i];
        }
       }return ans;
    }
};