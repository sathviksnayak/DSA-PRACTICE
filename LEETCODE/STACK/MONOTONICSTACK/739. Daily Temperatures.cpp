class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> answer(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            int x=temperatures[i];
            while(!s.empty() && x>=s.top().first){
                s.pop();
            }
            if(!s.empty()) answer[i]=s.top().second-i;
            s.push({x,i});
        }
        return answer;
    }
};