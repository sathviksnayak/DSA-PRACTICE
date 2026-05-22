class Solution {
public:
    string removeKdigits(string num, int k) {
            stack<char> s;
            string ans="";
            for(int i=0;i<num.size();i++){

                while(!s.empty() && s.top()>num[i] && k>0){
                    s.pop();
                    k--;
                }
                s.push(num[i]);

            }
            while(!s.empty() && k>0){
                s.pop();
                k--;
            }
            
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
           

            while(!ans.empty() && ans.back()=='0') ans.pop_back();
            
            reverse(ans.begin(),ans.end());
            
            if(ans=="") return "0";
    return ans;
    }
};