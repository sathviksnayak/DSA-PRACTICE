class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> q1,q2;
        int l=0;
        int maxl=0;
        int diff=0;
        for(int i=0;i<nums.size();i++){
            while(!q1.empty() && nums[q1.back()]>nums[i]) q1.pop_back();
            q1.push_back(i);
            while(!q2.empty() && nums[q2.back()]<nums[i]) q2.pop_back();
            q2.push_back(i);
            diff=abs(nums[q2.front()]-nums[q1.front()]);
            while(diff>limit){
                l++;
                while(!q1.empty() && q1.front()<l) q1.pop_front();
                while(!q2.empty() && q2.front()<l) q2.pop_front();
                diff=abs(nums[q2.front()]-nums[q1.front()]);
            }
            maxl=max(maxl,i-l+1);

        }

        return maxl;
    }
};