class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int startRow=0,endRow=matrix.size()-1,endCol=matrix[0].size()-1,startCol=0;
        vector<int> v;
        
        while(startRow<=endRow && startCol<=endCol){
            
            //start row
            for(int col=startCol;col<=endCol;col++)
                v.push_back(matrix[startRow][col]);
            
            //end column
            for(int row=startRow+1;row<=endRow;row++)
                v.push_back(matrix[row][endCol]);
                            
            //end row
            for(int col=endCol-1;col>=startCol;col--){
                
                //avoinding duplicate printing in row
                if(startRow==endRow)
                    break;
                v.push_back(matrix[endRow][col]);
            }
                
            //start column
            for(int row=endRow-1;row>=startRow+1;row--){
                
                //avoiding duplicate printing in column
                if(startCol==endCol)
                    break;
                v.push_back(matrix[row][startCol]);
            }
            
            //update variables to point inner spirals
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return v;
        
    }
};
