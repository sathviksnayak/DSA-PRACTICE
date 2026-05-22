class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> alpha(26,0);
        alpha['a'-'a']=1;
        alpha['e'-'a']=1;
        alpha['i'-'a']=1;
        alpha['o'-'a']=1;
        alpha['u'-'a']=1;

        int maxr=0,v=0;
        for(int i=0;i<k;i++){
            if(alpha[s[i]-'a']==1){
                v++;
            }
        }
        maxr=v;
        
        for(int i=k;i<s.size();i++){
            if(alpha[s[i-k]-'a']==1){
                v--;
            }
            if(alpha[s[i]-'a']==1){
                v++;
            }
            maxr=max(v,maxr);
        }
        return maxr;
    }
};