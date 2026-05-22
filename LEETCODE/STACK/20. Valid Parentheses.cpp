class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for(auto c:s){
            
            if(x.empty()){
                if(c=='}'||c==')'||c==']') return false;
                x.push(c);
            }
            else{
                
                char n='0';
                if(c==')')n='(';
                else if(c=='}') n='{';
                else if(c==']') n='[';
                
                if(n==x.top()) x.pop();
                else x.push(c);
                
                

            }
        }
        return x.empty();
    }
};