class Solution {
public:
    string clearDigits(string s) {
        stack<char> x;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                if(!x.empty()) x.pop();
            }
            else{
                x.push(s[i]);
            }
        }
        while(!x.empty()){
            ans+=x.top();
            x.pop();
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};