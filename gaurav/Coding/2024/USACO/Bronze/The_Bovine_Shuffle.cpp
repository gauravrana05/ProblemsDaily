/*
ID: gauravrana05
TASK: lostcow 
LANG: C++
*/

#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

#define rep(i,s,e) for(int i = s; i < e; i++)

using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


void solve () {
	int n;
    cin>>n;
    vector<int> shuffle; // new positions after shuffle
    vector<int> id; //order of the cows after 3 shuffles

    rep(i, 0, n){
        int input;
        cin>>input;
        shuffle.push_back(input);
    }

    rep(i, 0, n){
        int input;
        cin>>input;
        id.push_back(input);
    }    

    rep(i, 0, 3){
        vector<int> temp(n);
        rep(j, 0, n){
        temp[j] = id[shuffle[j] - 1]; //reverse shuffle 
        }
        id = temp;

    }
    rep(i, 0, n){
        cout<<id[i]<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("shuffle");
    solve();
    return 0;
}