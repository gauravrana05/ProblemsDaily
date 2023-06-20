class Solution {
public:
    vector<vector<string>> sol;

    void convert(vector<vector<int>> ans, int n){
        vector<string> t;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                if(ans[i][j]==1){
                    temp.push_back('Q');
                }
                else{
                    temp.push_back('.');
                }
            }
            t.push_back(temp);
        }
        sol.push_back(t);
    }

    vector<vector<int>> change(vector<vector<int>> t, int r, int c, int n){
        vector<vector<int>> ans = t;
        for(int i=0;i<n;i++){
            ans[r][i]=-1;
            ans[i][c]=-1;
        }
        int i = r,j = c;
        while(i>=0 && j>=0){
            ans[i][j]=-1;
            i--;
            j--;
        }

        i=r,j=c;
        while(i<n && j>=0){
            ans[i][j]=-1;
            i++;
            j--;
        }

        i=r,j=c;
        while(i>=0 && j<n){
            ans[i][j]=-1;
            i--;
            j++;
        }

        i=r,j=c;
        while(i<n && j<n){
            ans[i][j]=-1;
            i++;
            j++;
        }
        ans[r][c]=1;
        return ans;
    }

    void solve(int cur, int n, vector<vector<int>> ans){
        if(cur==n){
            convert(ans,n);
            return ;
        }
        for(int i=0;i<n;i++){
            if(ans[cur][i]!=-1){
                vector<vector<int>> k = change(ans,cur,i,n);
                solve(cur+1,n,k);
            }
        }
    }



    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        solve(0,n,ans);
        return sol;
    }
};