#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, int n, vector<vector<bool>> pos){
        int i = 0;
        while( i < row){
            if(pos[i][col] == true)
                return false;
            i++;
        }

         i = row;
        int j = col;

        while(i >=0 && j>=0){
            if(pos[i][j]==true)
                return false;
            i--;
            j--;
        }

         i = row;
         j = col;

        while(i >=0 && j < n){
            if(pos[i][j]==true)
                return false;
            i--;
            j++;
        }
        return true;
        
    }
    void solve(int row, int n, vector<vector<bool>> pos, vector<vector<string> > &board, vector<string> &ans){
        
        if(row == n){
                board.push_back(ans);
                return;
        }
            for(int col = 0; col < n; col++ ){
               
                if(isSafe(row, col, n, pos)){
                    pos[row][col] = true;
                    int i = 0;
                    string temp;
                    while( i < n){
                        if(i == col)
                            temp.push_back('Q');
                        else
                            temp.push_back('.');
                        i++;
                    }
                    ans.push_back(temp); //creating string ans

                    solve(row+1,n,pos,board,ans); //next call

                    pos[row][col] = 0;
                    ans.pop_back();
                }

            }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> board;
      vector<string> ans;
      vector<vector<bool> > pos(n, vector<bool>(n,false));
      
      solve(0, n, pos, board, ans);
      
      return board;  
    }
};