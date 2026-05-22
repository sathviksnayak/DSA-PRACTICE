class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> n(nums.size());
        int pos;
        int m=nums.size();
        for(int i=0;i<m;i++){
            pos=(i+k)%m;
            n[pos]=nums[i];
        }
        for(int i=0;i<m;i++){
            nums[i]=n[i];
        }
        
    }
};