#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool issafe(vector<vector<char>>& board, int row, int col, char dig){
    //horizontal
    for(int j=0;j<9;j++){
        
        if(board[row][j]==dig){
            return false;
        }
    }

    //vertical
    for(int i=0;i<9;i++){
        
        if(board[i][col]==dig){
            return false;
        }
    }

    //subbox
    int srow = (row/3)*3;
    int scol = (col/3)*3;
    for(int i=srow;i<=srow+2;i++){
        for(int j=scol;j<=scol+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;

}



bool solve(vector<vector<char>>& board, int row, int col){
    int nextrow,nextcol;
    nextrow=row;
    nextcol = col+1;
    if(row==9){
        return true;
    }
    if(nextcol==9){
        nextcol=0;
        nextrow=row+1;
    }

    if(board[row][col]!='.'){
        return solve(board,nextrow,nextcol);
    }
    for(char dig='1';dig<='9';dig++){
        if(issafe(board,row,col,dig)){
            board[row][col]=dig;
            if(solve(board,nextrow,nextcol)){
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}

bool sudokusolver(vector<vector<char>>& board){
    return solve(board,0,0);
}
int main(){
    vector<vector<char>> board = {{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};
    bool result = sudokusolver(board);
    cout<<result<<endl;
    
    
    


    return 0;
}
