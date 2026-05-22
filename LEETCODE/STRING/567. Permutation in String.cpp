class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0),win(26,0);
        for(char a:s1) freq[a-'a']++;
        vector<int> ans;
        for(int i=0;i<s2.size();i++){
            win[s2[i]-'a']++;
            if(i>=s1.size()){
                win[s2[i-s1.size()]-'a']--;
            }
            if(win==freq){
                return true;
            }
        }
        return false;
    }
};