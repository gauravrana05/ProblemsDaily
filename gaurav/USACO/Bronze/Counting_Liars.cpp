#include <iostream> 
#include<vector>
#define rep(i,s,e) for(int i = s; i < e; i++)
using namespace std;
int main(){
    int n; vector<pair<char, int>> entries; cin >> n;
    rep(i, 0, n) {char c;int val;cin >> c >> val; entries.push_back({c, val});}
    int ans = n;
    for (auto i : entries){
        int pos = i.second;
        int count = 0;
        for (auto j : entries)
            if ((j.first == 'G' && pos < j.second) || (j.first == 'L' && pos > j.second))
                count++;
        ans = min(count, ans);
    }
    cout << ans << endl;
    return 0;
}