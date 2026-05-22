class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int,int> first; 
        int prefix = 0, ans = 0;

        for(int i = 0; i < n; i++){
            
         
            if(hours[i] > 8) prefix += 1;
            else prefix -= 1;

           
            if(prefix > 0){
                ans = i + 1;
            }
            else{
                
                if(first.count(prefix - 1)){
                    ans = max(ans, i - first[prefix - 1]);
                }
            }

         
            if(!first.count(prefix)){
                first[prefix] = i;
            }
        }

        return ans;
    }
};