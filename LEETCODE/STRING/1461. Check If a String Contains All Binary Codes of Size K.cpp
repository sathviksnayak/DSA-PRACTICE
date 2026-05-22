class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> sub;
        
        int l=0;
   for(int i=k-1;i<s.size();i++){
        if(i-l<=k-1){
            string x;
            for(int j=l;j<=i;j++) x.push_back(s[j]);
            sub.insert(x);
            l++;
        }

   }
return sub.size()==(1LL<<k);     
    }
};