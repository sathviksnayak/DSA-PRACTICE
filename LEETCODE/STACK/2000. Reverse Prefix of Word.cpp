class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> x;
        int n=-1;

        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                x.push(word[i]);
                n=i;
                break;
            }
            else{
                x.push(word[i]);
            }
        }
        if(n==-1) return word;
        for(int i=0;i<=n;i++){
            word[i]=x.top();
            x.pop();
        }return word;
    }
};