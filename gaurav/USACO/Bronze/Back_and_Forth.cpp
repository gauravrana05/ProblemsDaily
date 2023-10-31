// #include<bits/stdc++.h>
#include<vector>
#include<set>
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

set<int> possible;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void get_possible(int day, int a_tank, vector<int> a_buckets, int b_tank,vector<int> b_buckets){
    
    if(day == 4){
        possible.insert(a_tank);
        return;
    }
    for(int i=0; i<a_buckets.size(); i++){
        
        int t = a_buckets[i];

        vector<int> new_a = a_buckets;
        
        new_a.erase(begin(new_a) + i);

        vector<int> new_b = b_buckets;
        new_b.push_back(t);

        get_possible(day + 1, b_tank + t, new_b, a_tank - t, new_a);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    setIO("backforth");
    
    vector<int> a(10);
    for( int &i:a){cin>>i;}
    
    vector<int> b(10);
    for(int &i: b){cin>>i;}
    get_possible(0,1000, a, 1000, b);
    
    cout << possible.size() << endl;

    return 0;
}