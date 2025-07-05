#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<string>> ans;
    bool issafe(vector<string>& board, int row, int col, int n){
        //vertical
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nqueens(vector<string> &board, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(board,row,col,n)){
                board[row][col] = 'Q';
                nqueens(board,row+1,n);
                board[row][col]='.';//backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nqueens(board,0,n);
        return ans;
    }
int main(){
    int n = 9;
    vector<vector<string>> result = solveNQueens(n);
    for (const auto& board : result){
        for (const auto& row : board){
            cout << row << " "; 
        } 
    cout << endl;
    } // Add a new line after each board for clarity }
    // cout<<result.size()<<endl;
}

//Time Complexity: O(n!)