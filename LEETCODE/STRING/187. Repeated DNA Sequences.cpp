class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> count;
        int l=0;
        if(s.size()<10) return ans;
        for(int r=0;r<=s.size()-10;r++){
            string sub;
            for(int i=r;i<r+10;i++){
                sub.push_back(s[i]);
            }
            count[sub]++;
            if(count[sub]>1){
                ans.push_back(sub);
                count[sub]=-s.size();
            }


        }

       return ans; 
    }
};