class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int right=n-1,left=0,bottom=n-1,top=0;
        int ele=1;
        char dir='r';
        int i=0,j=0;
       while(ele<=n*n){
                matrix[i][j]=ele++;
                if(dir=='r'){
                    if(j==right){
                        top++;
                        dir='d';
                        i++;
                    }
                    else{
                        j++;
                    }
                }
                else if(dir=='d'){
                    if(i==bottom){
                        right--;
                        j--;
                        dir='l';
                    }
                    else{
                        i++;
                    }
                }
                else if(dir=='l'){
                    if(j==left){
                        bottom--;
                        i--;
                        dir='u';
                    }
                    else{
                        j--;
                    }
                }
                else if(dir=='u'){
                    if(i==top){
                        left++;
                        j++;
                        dir='r';
                    }
                    else{
                        i--;
                    }
                }
          
       }

       return matrix;
      
    }
};