/*
ID: gauravrana05
TASK: lostcow 
LANG: C++
*/

/*
Logic:
For every individual cow during time s we need b buckets and 
after time t we not need those buckets

We can maintain a variable, add b(i) when we reach time s and 
subtract b(i) when we reach time t for each individual cow
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>

#define rep(i,s,e) for(int i = s; i < e; i++)

using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


void solve () {
	int n; cin>>n;

    set<pair<int, int>> s;//we'll maintain a set for the  sorted time

    rep(i, 0, n){
        int st, end, b; cin>>st>>end>>b;
        
        s.insert({st, b});// as we reach time st we'll add b buckets
        s.insert({end, -b}); // as we reach time end we'll add -b buckets
    }

    int ans = 0, count = 0;
    
    for(auto i : s){
        count+= i.second; //we'll keep adding and removing the buckets with time
        ans = max(ans, count);// and see at what time we required the maximum number of buckets
    }
    cout<<ans<<endl; // the max number of buckets at any instant will be the answer
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("blist");

    solve();
    return 0;
}