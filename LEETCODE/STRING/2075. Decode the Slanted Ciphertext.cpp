class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size()/rows;
        string ans;
        int s=encodedText.size();

        if(rows==1 || s<2) return encodedText;
        /*vector<vector<char>> mat(rows,(vector<char>(cols)));
        int l=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                char x=encodedText[l++];
                mat[i][j]=x;
            }
        }

        for(int j=0;j<cols;j++){
            for(int i=0,k=j;i<rows && k<cols;i++,k++){
                
                ans.push_back(mat[i][k]);
            }
        }*/
    //ch...ie...pr
  int i=0,j=0,x=1;
  while(i<rows && j<cols){
    ans.push_back(encodedText[i*cols+j]);
    if(i==0&& j==cols-1) break;
    i++,j++;
    if(i==rows) {j=x++;
    i=0;
    }
  }

        int l=ans.size()-1;
       while(!ans.empty() && ans.back() == ' ') {
    ans.pop_back();
}
        return ans;
    }
};