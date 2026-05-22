class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int maxc=0,l=0,r=0;

        for(char x:moves){
            if(x=='L'){
                l++;
                r--;
            }else if(x=='R'){
                l--;
                r++;
            }
            else{
                r++;
                l++;
            }
        
        }
        maxc=max(l,r);
        return maxc;

    }
};                                                                                                                               