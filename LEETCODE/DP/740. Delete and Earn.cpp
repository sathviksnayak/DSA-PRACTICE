class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxval=*max_element(nums.begin(),nums.end());

        vector<long long> points(maxval+1,0);
        for(int i:nums){
            points[i]+=i;
        }
        long long take =0,skip=0;
        for(int i=0;i<points.size();i++){
            long long takenow=skip+points[i];
            long long skipnow=max(take,skip);
            take=takenow;
            skip=skipnow;


        }
        return (int)max(take,skip);
    }
};