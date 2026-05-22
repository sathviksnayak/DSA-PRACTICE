class Solution {
public:
    string decodeString(string s) {
      string ans="";
      int k=0;
    string curr="";
    stack<string> x; 
    stack<int> s1;
      for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') k=k*10+s[i]-'0';
         else if(s[i]=='['){
            
            s1.push(k);
            x.push(curr);
            curr="";
            k=0;
         }
        else if(s[i]>='a' && s[i]<='z') curr+=s[i];
        else if(s[i]==']'){
        
            string temp=curr;
            curr="";
            for(int i=0;i<s1.top();i++){
                curr+=temp;
            }curr=x.top()+curr;
            x.pop();
            s1.pop();
        }
      }
      return curr;
    }
};