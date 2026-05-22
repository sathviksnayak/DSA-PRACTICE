class Solution {
public:
    bool subboxvalid(vector<vector<char>>& board,int i,int j){
        vector<bool> subbox(10,false);
        int n=i+3,m=j+3;

        for(;i<n;i++){
            for(int k=j;k<m;k++){
                if(board[i][k]=='.') continue;
                else if(subbox[board[i][k]-'0']) return false;
                
                else{
                    subbox[board[i][k]-'0']=true;
                }
            }
           
        }

        return true;


    }
    bool isValidSudoku(vector<vector<char>>& board) {
         int i=0,j=0;
         
         for(;i<9;i+=3){
            for(j=0;j<9;j+=3){
            if(!subboxvalid(board,i,j)) return false;
         
            }
         }
        for(int i=0;i<9;i++){
            vector<bool> row(10,false);
            vector<bool> col(10,false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') {}
                else if(row[board[i][j]-'0']) return false;
                else{
                    row[board[i][j]-'0']=true;
                }
                if(board[j][i]=='.') continue;
                else if(col[board[j][i]-'0']) return false;
                else {
                    col[board[j][i]-'0']=true;
                }
            }
            }
            

         return true;
    }
};