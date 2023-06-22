class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        dp[1].push_back("()");
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<dp[j].size();k++){
                    string temp;
                    temp.push_back('(');
                    temp+=(dp[j][k]);
                    temp.push_back(')');
                    for(int l=0;l<dp[i-j-1].size();l++){
                        string m = temp + dp[i-j-1][l];
                        dp[i].push_back(m);
                    }
                }
            }
        }
        return dp[n];
    }
};
