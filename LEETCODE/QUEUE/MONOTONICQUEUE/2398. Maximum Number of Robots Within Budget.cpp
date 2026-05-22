class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> q;
        long long sum=0;
        int l=0;
        long long total=0;
        int k=0;
        int maxk=0;

        for(int i=0;i<chargeTimes.size();i++){
            
            while(!q.empty() && chargeTimes[q.back()]<chargeTimes[i]) q.pop_back();
            q.push_back(i);
            k=i-l+1;
            sum+=runningCosts[i];
            total=chargeTimes[q.front()]+k*sum;
            while(total>budget ){

                sum-=runningCosts[l];
                l++;
                while(!q.empty() && q.front()<l) q.pop_front();
                k=i-l+1;
                if(q.empty() && l>i){
                    k=0;
                    total=0;
                    sum=0;
                    break;
                }
                total=chargeTimes[q.front()]+k*sum;
                
                }
                maxk=max(k,maxk);
            
        }
        return maxk;
    }
};