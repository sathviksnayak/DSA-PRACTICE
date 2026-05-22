class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 0;
        int minele=*min_element(nums.begin(),nums.end());
        int maxele=*max_element(nums.begin(),nums.end());
        if(maxele==minele) return 0;
        int bucketsize=ceil((double)(maxele-minele)/(n-1));
        int bucketcount=n-1;

        vector<int> bucketmax(bucketcount,INT_MIN);
        vector<int> bucketmin(bucketcount,INT_MAX);
        vector<bool> used(bucketcount,false);


        for(int i=0;i<n;i++){
            if(nums[i]==maxele || nums[i]==minele) continue;

            int index=(nums[i]-minele)/bucketsize;
            bucketmax[index]=max(bucketmax[index],nums[i]);
            bucketmin[index]=min(bucketmin[index],nums[i]);
            used[index]=true;
        }
            int maxgap=0;
            int pre=minele;

            for(int i=0;i<bucketcount;i++){
                if(!used[i]) continue;
                maxgap=max(maxgap,bucketmin[i]-pre);
                pre=bucketmax[i];
            }

        maxgap=max(maxgap,maxele-pre);
        return maxgap;

    }
};