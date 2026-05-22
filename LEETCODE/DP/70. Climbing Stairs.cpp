class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        int s1=1,s2=2,cur;
        

        for(int i=3;i<=n;i++){
            cur=s1+s2;
            s1=s2;
            s2=cur;
        }
        return s2;
        
    }
};