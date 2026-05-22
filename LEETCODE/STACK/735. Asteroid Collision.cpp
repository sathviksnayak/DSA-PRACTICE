class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            int rock=asteroids[i];
            if(s.empty()){
                s.push(rock);
            }
            else {
                

                if(s.top()>0 && rock<0){
                    bool destroyed=false;
                    while(!s.empty() && s.top()>0 && rock<0){
                        if(abs(s.top())>abs(rock)){
                            destroyed=true;
                            break;
                        }
                        else if(abs(s.top())==abs(rock)){
                            destroyed=true;
                            s.pop();
                            break;
                        }
                        s.pop();
                    }

                    if(!destroyed) s.push(rock);
                }
                else{
                    s.push(rock);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }reverse(ans.begin(),ans.end());
        return ans;

    }
};