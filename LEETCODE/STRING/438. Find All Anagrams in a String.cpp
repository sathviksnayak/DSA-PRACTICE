class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0),win(26,0);
        for(int i=0;i<p.size();i++){
            freq[p[i]-'a']++;
        }
    vector<int> ans;
    if(s.size()<p.size()) return ans;

        for(int r=0;r<s.size();r++){
            win[s[r]-'a']++;
            if(r>=p.size()){
                win[s[r-p.size()]-'a']--;
            }
            if(win==freq){
                ans.push_back(r-p.size()+1);
            }
        }
        return ans;
    }
};