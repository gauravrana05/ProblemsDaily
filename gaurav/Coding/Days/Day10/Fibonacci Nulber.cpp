class Solution {
public:
    int fib(int n) {

        int prev1 = 1;
        int prev2 = 0;
        if(n==0)
            return prev2;
        if(n == 1)
            return prev1;
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = prev1 + prev2;
            cout<<ans<<" ";
            prev2 = prev1;
            prev1 = ans;

        }
        return ans;

        
    }
};