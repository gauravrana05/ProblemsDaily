#include<bits/stdc++.h>

using namespace std;

void solve(){
    
    long long  n;
    cin >> n;

    vector<long long > maxAmt(n);
    for(auto &i: maxAmt)
        cin >> i;
    
    sort(maxAmt.begin(), maxAmt.end());

    unsigned long long mAmt = 0, val;

    for(auto i = 0; i < maxAmt.size(); i++){
        auto nAmt = (maxAmt.size() - i) * maxAmt[i];
        if(nAmt > mAmt){
            val = maxAmt[i];
        }
        mAmt = max(mAmt, nAmt );

    }
    cout<<mAmt<<" "<<val<<endl;
}

int main(){
        solve();
    return 0;
}