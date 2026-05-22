class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1,val;
        bool zero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){ 
            if(zero){
            for(int j=0;j<nums.size();j++) nums[j]=0;
            return nums;
            }
            zero=true;
            continue;
            }
            pro*=nums[i];

        }
        for(int i=0;i<nums.size();i++){
            if(zero){
                if(nums[i]==0){
                    nums[i]=pro;
                }else{
                    nums[i]=0;
                }
            }else{
            val=nums[i];
            if(val!=0)
            nums[i]=pro/val;
            }
        }
        return nums;
    }
};