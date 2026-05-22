class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int last2val=nums[0],lastin=0,k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==last2val){
                if(i-lastin>=2){
                    continue;
                }
                else{
                    nums[k]=nums[i];
                    k++;
                }

            }
            else{
                last2val=nums[i];
                lastin=i;
                nums[k]=nums[i];
                k++;
            }

        }

        return k;
    }
};