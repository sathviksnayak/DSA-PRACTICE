class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> n2;
        for(int i=0;i<2*nums.size();i++){
            n2.push_back(nums[i%nums.size()]);
        }
        for(int i=n2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=n2[i]){
                s.pop();
            }
            if(i<nums.size()){
                if(s.empty()) nums[i]=-1;
                else nums[i]=s.top();

            }
            s.push(n2[i]);
        } return nums;
    }
};