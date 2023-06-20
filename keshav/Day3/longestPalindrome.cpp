class Solution {
public:

    void check(string s, int l, int r, string &k){
        int n = s.size();
        while(l>=0&&r<n&&s[l]==s[r]){
            l--;
            r++;
        }
        if( r-l-1 > k.size()){
            k = s.substr(l+1,r-l-1);
        }
    }

    string longestPalindrome(string s) {
        int ans =0;
        int n = s.size();
        if(n==1){
            return s;
        }
        string k ="";
        for(int i=0;i<n-1;i++){
            check(s,i,i,k);
            check(s,i,i+1,k);
        }
        return k;
    }
};