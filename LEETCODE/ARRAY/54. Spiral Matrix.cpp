class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        int i = 0, j = 0;
        char dir = 'r';

        for (int count = 0; count < m * n; count++) {

            spiral.push_back(matrix[i][j]);

            if (dir == 'r') {
                if (j == right) {
                    dir = 'd';
                    top++;
                    i++;
                } else {
                    j++;
                }
            }
            else if (dir == 'd') {
                if (i == bottom) {
                    dir = 'l';
                    right--;
                    j--;
                } else {
                    i++;
                }
            }
            else if (dir == 'l') {
                if (j == left) {
                    dir = 'u';
                    bottom--;
                    i--;
                } else {
                    j--;
                }
            }
            else { 
                if (i == top) {
                    dir = 'r';
                    left++;
                    j++;
                } else {
                    i--;
                }
            }
        }

        return spiral;
    }
};