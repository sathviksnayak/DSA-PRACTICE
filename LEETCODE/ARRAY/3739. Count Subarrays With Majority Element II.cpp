class Solution {
public:
   vector<int> bit;
   int n;
   void add(int i){
    while(i<=n){
        bit[i]++;
        i+=i&-i;
    }
   }
   int get(int i){
    int x=0;
    while(i>0){
        x+=bit[i];
        i-=i&-i;
    }
    return x;
   }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int sz=nums.size();
        int offset=sz+1;


        n=2*sz+2;
        bit.resize(n+1,0);
        int pref=0;
        long long ans=0;
        add(offset);
        for(int x:nums){
            pref+=x==target?1:-1;
            ans+=get(pref+offset-1);
            add(pref+offset);
        }
        return ans;
    }
};