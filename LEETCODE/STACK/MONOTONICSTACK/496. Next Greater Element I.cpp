class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> in;
        for(int i=0;i<nums2.size();i++){
            in[nums2[i]]=i;
        }
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && nums2[i]>s.top()){
                s.pop();
            }
            int a=nums2[i];
            if(s.empty()) nums2[i]=-1;
            else nums2[i]=s.top();
            s.push(a);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=nums2[in[nums1[i]]];
        }
        return nums1;
    }
};