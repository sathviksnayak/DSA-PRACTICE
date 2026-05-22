class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mind=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(words[i]==target ){
                
                mind=min(mind,min(abs(startIndex-i),n-abs(startIndex-i)));
            }

        }
        return mind==INT_MAX?-1:mind;
        
     
    }
};