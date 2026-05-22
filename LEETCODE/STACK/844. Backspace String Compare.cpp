class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                  if(!s1.empty())
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        string a;
        while(!s1.empty()){
            a.push_back(s1.top());
            s1.pop();
        }
                for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!s1.empty())
                s1.pop();
            }
            else{
                s1.push(t[i]);
            }
        }
        for(int i=0;i<a.size();i++){
            if(s1.empty()) return false;
            if(a[i]!=s1.top()) return false;
            
            s1.pop();
        }
        if(!s1.empty()) return false;
        return true;
    }
};