class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> fr;
        vector<int> c(26,0);
        int unique=0;
        for(int i=0;i<minSize;i++){
            if(c[s[i]-'a']==0) unique++;
            c[s[i]-'a']++; 
        }
        int maxocc=0;
        if(unique<=maxLetters){ fr[s.substr(0,minSize)]++;
        maxocc=1;
        }
        for(int i=minSize;i<s.size();i++){
            c[s[i-minSize]-'a']--;
            if(c[s[i-minSize]-'a']==0) unique--;
            if(c[s[i]-'a']==0) unique++;
            c[s[i]-'a']++;
            if(unique<=maxLetters){
                fr[s.substr(i-minSize+1,minSize)]++;
                maxocc=max(maxocc, fr[s.substr(i-minSize+1,minSize)]);
            }
        }
        return maxocc;
    }
};