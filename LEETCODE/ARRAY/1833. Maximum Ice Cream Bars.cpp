class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxcost=*max_element(costs.begin(),costs.end());

        vector<int> bucket(maxcost+1,0);
        for(int x:costs){
            bucket[x]++;
        }

        int ans=0;
        for(int i=1;i<=maxcost && i<=coins;i++){
            if(bucket[i]!=0){
                int canBuy = min(bucket[i], coins / i);

                ans += canBuy;
                coins -= canBuy * i;
            }
        }
        return ans;
    }
};