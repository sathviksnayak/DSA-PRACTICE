class Solution {
public:
    int numSteps(string s) {
        int lastele=s.size()-1;
        int steps=0;
      
        while(lastele>0){
            if(s[lastele]=='1'){
                char carry='1';
                
                for(int i=lastele;i>=0;i--){
                    if(s[i]=='1' && carry=='1'){
                       s[i]='0';
                        carry='1';

                    }
                    else if( carry=='0'){ 
                        break; 
                    }
                    else{
                        s[i]=carry;
                        carry='0';
                    }
                    

                }
                if(carry=='1'){ s='1'+s;
                lastele++;
                }

               
              
            }
            else{
                lastele--;
               
            }
            steps++;
        }
        return steps;

        
    }
};