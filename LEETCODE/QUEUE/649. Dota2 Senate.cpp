class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int rc=0,dc=0;
        for( char a:senate) {q.push(a);
        if(a=='R') rc++;
        else dc++;
        }
        int rr=0,rd=0;
        while(!q.empty()){
            char a=q.front();
            if(a=='R' && dc==0) return "Radiant";
            else if(a=='D' && rc==0) return "Dire";

           if(a=='R'){
            if(rr>0){
                q.pop();
                rr--;
                rc--;
            }
            else{
                rd++;
                q.push(a);
                q.pop();
            }
           }
           else{
            if(rd>0){
                q.pop();
                rd--;
                dc--;
            }else{
                rr++;
                q.push(a);
                q.pop();
            }

           }

        }
        return "";
    }
};