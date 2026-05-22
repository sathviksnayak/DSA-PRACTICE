class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> qi;
        deque<int> qd;
        long long cost=0;
        long long ans=0;
        int l=0;
        
        for(int i=0;i<nums.size();i++){
            while(!qi.empty() && nums[qi.back()]>nums[i]) qi.pop_back();
            qi.push_back(i);
            while(!qd.empty() && nums[qd.back()]<nums[i]) qd.pop_back();
            qd.push_back(i);
            long long diff=((long long)nums[qd.front()]-nums[qi.front()]);
            cost=diff*(i-l+1);
            while(cost>k){
                l++;
               while(!qi.empty() && qi.front()<l) qi.pop_front();
               while(!qd.empty() && qd.front()<l) qd.pop_front();
               long long diff=((long long)nums[qd.front()]-nums[qi.front()]);
               cost=diff*(i-l+1);
            }
            
            ans+=(i-l+1);
        }
    return ans;
    }
};