#include<bits/stdc++.h>

using namespace std;


void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve(){

    int n;
    string s;
    cin>>n>>s;
    int size = 2;
    map<string, int> mp;

    for( int i = 0; i < n; i++){
        for (int j= i+1; j<n; j++){
            string temp = s.substr(i, j + 1 - i);
            
            if(temp.length() >= size){

            if(mp.count(temp) == 1){
                mp.erase(temp);
                size = temp.length() + 1;
            }
            else{
                mp[temp]++;
            }
            }
        }
    }
    cout<<size<<endl;

}
int main(){
    ios_base::sync_with_stdio(0);
    setIO("whereami");
    solve();
    return 0;
}