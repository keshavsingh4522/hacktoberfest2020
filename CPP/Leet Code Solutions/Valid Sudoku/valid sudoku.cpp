class Solution {
public:
bool isValidRow(vector<vector<char>> &board,int row)
{
    unordered_map<char,int>map;
    int count =1;
    for(int i=0;i<9;i++)
    {
        if(board[row][i]=='.')
            continue;
        
        if(map.find(board[row][i]) != map.end())
            return false;
        map[board[row][i]] = count++;
    }
    count =1;
    map.clear();
    return true;

}

bool isValidCol(vector<vector<char>> &board,int col)
{
    unordered_map<char,int>map;
    int count =1;
    for(int i=0;i<9;i++)
    {
        if(board[i][col]=='.')
            continue;
        
        if(map.find(board[i][col]) != map.end())
            return false;
        map[board[i][col]] =  count++;
    }
    count =1;
    map.clear();
    return true;

}

bool isValidMat(vector<vector<char>> &board,int index)
{
    unordered_map<char,int>map;
    int count =1;
    int Row=(index/3)*3;
    int Col=(index%3)*3;
    for(int j=Row;j<Row+3;j++)
    {
        for(int k=Col;k<Col+3;k++)
        {
            if(board[j][k] == '.')
                continue;
            
            if(map.find(board[j][k]) != map.end())
                return false;
            map[board[j][k]] =  count++;
        }
        
    }
    count =1;
    map.clear();
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    bool val;
    for(int i =0;i<board.size();i++)
    {
        val = isValidCol(board,i);
        if(!val)
            return false;

        val = isValidRow(board,i);
        if(!val)
            return false;
        val = isValidMat(board,i);
        if(!val)
            return false;
    }
    return true;
    
}
};
