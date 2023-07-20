class Solution {
public:
    

    vector<int> getRow(int n) {
        vector<vector<int>> ans(n+1,vector<int> (n+1,1)) ;
        
        for(int i=2;i<=n;i++){
            for(int j=1; j<i;j++){
                ans[i][j]= ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
            return ans[n];
        
        
    }
};