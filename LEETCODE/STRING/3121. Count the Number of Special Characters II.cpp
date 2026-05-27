class Solution {
public:
    int numberOfSpecialChars(string word) {
       vector<int> small(26,INT_MAX),big(26,-1);
        int ans=0;
    for( int i=0;i<word.size();i++){
         char c=word[i];
        if(c>='a' && c<='z'){
            small[c-'a']=i;
        }
        else{
            if(big[c-'A']==-1){
                big[c-'A']=i;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(small[i]<big[i]){
            ans++;
        }
    }
return ans;
    }
};