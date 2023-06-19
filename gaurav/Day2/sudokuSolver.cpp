#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:

bool isSafe(int r, int c, vector<vector<char> > board, char val){
    
    for(int i = 0; i < board[0].size(); i++){
        if(board[r][i] == val)
            return false;
    }
    for(int i = 0; i < board[0].size(); i++){
        if(board[i][c] == val)
            return false;
    }

     for(int i = 0; i < board[0].size(); i++){
        if(board[(3 * (r/3) + i/3 )][3 * (c/3) + i%3] == val)
            return false;
    }
    
    return true;
}

bool solve(vector<vector<char> > & board){
    int n = board[0].size();

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            if(board[row][col] == '.'){
                for(char val = '1'; val <= '9'; val++){
                    if(isSafe(row, col,board,val)){
                        
                        board[row][col] = val;
                        bool solPossible = solve(board);  
                        if(solPossible)
                            return true;
                        else
                            board[row][col] = '.';


                    }
                }
                return false;
            }
        }
    }

    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        bool possible = solve(board);

        if(!possible){
            cout<<"Solution to the given sudoku is not possible\n";
        }
        else 
        return;
    }
};