#include<bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


void solve(){
    int n;
    cin>>n;

    vector<pair<int, int> > cT(n);

    for( auto &i: cT){
        cin>>i.first;
        cin>>i.second;
    }
    sort(cT.begin(), cT.end());

    unsigned long long int currentTime = 0;
    unsigned long long int cowIndex = 0;
    while(true){
        if(cowIndex == cT.size())
            break;
            if(currentTime >= cT[cowIndex].first ){
                currentTime += cT[cowIndex].second;
                cowIndex++;
                continue;
            }

            currentTime++;
    }
    cout<<currentTime<< endl;

}
int main(){
    ios_base::sync_with_stdio(0);
    setIO("cowqueue");
    solve();
    return 0;
}