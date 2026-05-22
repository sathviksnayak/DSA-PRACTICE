class Solution {
public:
    string minRemoveToMakeValid(string s) {
     int open=0;
     int close=0;
    string final;
     int k=-1;
     for(int i=0;i<s.size();i++){
        if(!open && s[i]==')'){
            continue;
        }
        else if(open && s[i]==')'){
           
            open--;
        }
        if(s[i]=='('){
           
            open++;
        }
        s[++k]=s[i];

     }
     for(int i=k;i>=0;i--){
        if(!close && s[i]=='('){
            continue;
        }
        else if(close && s[i]=='('){
            close--;
            
          

        }
        else if(s[i]==')') close++;
        final.push_back(s[i]);
     }
     reverse(final.begin(),final.end());
    return final;
    }
};