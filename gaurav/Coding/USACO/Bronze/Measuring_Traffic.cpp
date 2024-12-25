/*
ID: gauravrana05
TASK: lostcow 
LANG: C++
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>

#define mp make_pair

#define rep(i,s,e) for(int i = s; i < e; i++)
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve () {

    int n; cin>>n;
    vector<int> ramp(n);
    vector<pair<int, int> > range(n);

    rep(i, 0, n){
        string s;
        int l, h;
        cin>>s>>l>>h;
        if(s == "on")
            ramp[i] = 1;
        else if(s == "off")
            ramp[i] = 0;
        else
            ramp[i] = 2;
        range[i] = mp(l, h);
        
    }
    int index = n ;
    int st_ans_l = -1e5, st_ans_h = 1e5;
    int temp = index - 1;

    while(temp >= 0){
       
        if(ramp[temp] == 1){
            st_ans_l -= range[temp].second;
            st_ans_h -= range[temp].first;
            st_ans_l = max(0, st_ans_l);
        }
        else if(ramp[temp] == 0){
            st_ans_l += range[temp].first;
            st_ans_h += range[temp].second;
        }
        else{
            st_ans_h = min(st_ans_h, range[temp].second);
            st_ans_l = max(st_ans_l, range[temp].first);
        }

        temp--;
    }

    cout<<st_ans_l<<" "<<st_ans_h<<endl;

    index = 0;
    int end_ans_l = -1e5, end_ans_h = 1e5;
    temp = index;
    while(temp < n){
        
        if(ramp[temp] == 1){
            end_ans_l += range[temp].first;
            end_ans_h += range[temp].second;
        }
        else if(ramp[temp] == 0){
            end_ans_l -= range[temp].second;
            end_ans_h -= range[temp].first;
            end_ans_l = max(0, end_ans_l);
        }
        else{
            end_ans_h = min(end_ans_h, range[temp].second);
            end_ans_l = max(end_ans_l, range[temp].first);
        }

        temp++;
    }
    cout<<end_ans_l<<" "<<end_ans_h<<endl;



	
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("traffic");

    solve();
    return 0;
}