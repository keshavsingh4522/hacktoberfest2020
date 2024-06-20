class Solution {
public:
    void SetMinusONeTwoRowsAndColumn(vector<vector<int>>& matrix,int i,int j,int r,int c){
        for(int k=0;k<r;k++){
            if(k==i|| matrix[k][j]==0){
                continue;
            }
            matrix[k][j]=-1;
        }
        for(int k=0;k<c;k++){
            if(k==j || matrix[i][k]==0){
                continue;
            }
            matrix[i][k]=-1;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int count=0;
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    count++;
                    SetMinusONeTwoRowsAndColumn(matrix,i,j,r,c);
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==-1 && count>0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    //backtarcing
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}