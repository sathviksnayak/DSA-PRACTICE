class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<pair<int,int>,char>> s;
        vector<tuple<int,int,char,int>> robots;
        vector<int> ans0(healths.size(),0);
        vector<int> ans1;
        for(int i=0;i<healths.size();i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(),robots.end());
        vector<int> ans;
        for(int i = 0; i < robots.size(); i++){
    auto [pos, health, dir, idx] = robots[i];

    while(!s.empty() && s.top().second == 'R' && dir == 'L'){
        if(health>s.top().first.second){
            health--;
            s.pop();
        }
        else if(health==s.top().first.second){
            health=0;
            s.pop();
            break;
        }
        else{
            health=0;
            s.top().first.second--;
            break;
        }
    }
    if(health!=0) s.push({{idx,health},dir});
            
        }

        while(!s.empty()){
        ans0[s.top().first.first]=s.top().first.second;
        s.pop();
        }
       for(int i=0;i<ans0.size();i++){
        if(ans0[i]!=0){
            ans1.push_back(ans0[i]);
        }
       }
        return ans1;
    }
};