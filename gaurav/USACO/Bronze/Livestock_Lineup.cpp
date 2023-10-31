
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

vector<string> cows, beside_a, beside_b;
int N;
int where(string c){
    for(int i = 0; i<8; i++)
        if(cows[i] == c)
            return i;
    return -1;
}

bool statisified_constraints(void){
    for(int i; i<N; i++)
        if(abs(where(beside_a[i]) - where(beside_b[i])) != 1)
            return false;
    return true;
}

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve () {

    cin>>N;
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    string a, b, t;
    for(int i=0; i<N; i++){
        cin>>a;
        cin>>t;
        cin>>t;
        cin>>t;
        cin>>t;
        cin>>b;
        beside_a.push_back(b);
        beside_b.push_back(a);
    }
    do
    {
        if(statisified_constraints()){
            for(int i=0; i<8; i++){
                cout<<cows[i]<<endl;
            }
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));
    
}



int main() {
    ios_base::sync_with_stdio(0);
    setIO("lineup");

    solve();
    return 0;
}