class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window;
        int oldvalue=nums[0];
        window.insert(nums[0]);
        int j=0;
        long long left,right;
        for(int i=1;i<nums.size();i++){
            left=nums[i]-valueDiff;
            right=nums[i]+valueDiff;
            auto n=window.lower_bound(left);
            if(n!=window.end() && *n<=right) return true;
        
            else{
                window.insert(nums[i]);
                if(window.size()>indexDiff){
                    window.erase(window.find(oldvalue));
                    oldvalue=nums[++j];
                }
            }
        }

   
    
        return false;
    }
};