class Solution {
public:
    bool canBeEqual(string s1, string s2) {
     
    char temp;
    for(int i=0;i<s2.size();i++){
        if(s1[i]!=s2[i] ){
            if(i<2)
            if(s1[i+2]!=s2[i] || s1[i]!=s2[i+2]) return false;
            if(i>1)
            if(s1[i-2]!=s2[i] || s1[i]!=s2[i-2]) return false;
        }


    }
    

     return true;
    }
};