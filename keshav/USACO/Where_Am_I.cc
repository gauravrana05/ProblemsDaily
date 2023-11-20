#include <bits/stdc++.h>

using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<string, int> mp;
    bool flag = false;
    int ans = n;
    for (int i = 1; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - i + 1; j++)
        {

            string temp = s.substr(j, i);
            // cout<<i<<" "<<j<<" "<<temp<<endl;
            
            if(mp[temp]){
                flag = true;
                break;
            }    
            mp[temp]++; 
                
        }
        if(!flag){
            ans = i;
            break;
            }       
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    setIO("whereami");
    solve();
    return 0;
}