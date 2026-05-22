class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxfreq=0,maxlength=0,l=0;


        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        }

        return maxlength;
    }
};