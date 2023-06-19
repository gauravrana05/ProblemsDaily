#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>> board, int row, int col, char val){
        
        for(int i=0; i< 9; i++){
           
            if(board[row][i] == val || board[i][col] == val){
                return false;
            }

            if(board[3*(row/3) + i/3][3*(col/3) + i % 3] == val)
                return false;
        }
        return true;

    }


    bool solve(vector<vector<char> > &board){

        for(int i = 0 ;i < 9; i++){
            for( int j = 0; j < 9; j++){

                if(board[i][j] =='.')continue;

                char val = board[i][j];
                board[i][j] = '.';
                if(!isSafe(board, i, j, val)){
                    return false;}

                    board[i][j] = val;
                    
                    }
                }
                
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};
