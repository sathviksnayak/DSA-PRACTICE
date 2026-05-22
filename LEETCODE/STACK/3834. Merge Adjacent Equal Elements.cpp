class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> s;
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            if(s.empty()) s.push(x);
            else{
                
                while(!s.empty() && s.top()==x){
                    x=x+s.top();
                    s.pop();
                }
                s.push(x);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};