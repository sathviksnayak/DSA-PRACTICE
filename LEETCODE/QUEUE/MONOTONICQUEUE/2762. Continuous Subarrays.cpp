class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> iq,dq;
        int l=0;
        long long maxs=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            while(!iq.empty() && nums[iq.back()]>x) iq.pop_back();
            iq.push_back(i);
            while(!dq.empty() && nums[dq.back()]<x) dq.pop_back();
            dq.push_back(i);

            while((nums[dq.front()]-nums[iq.front()])>2){
                l++;
                if(dq.front()<l) dq.pop_front();
                if(iq.front()<l) iq.pop_front();
            }
            maxs+=(i-l+1);

            
        }
        return maxs;
    }
};