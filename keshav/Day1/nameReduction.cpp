#include <iostream>
using namespace std;


void solve(){
    string a,b,c;
    cin>>a>>b;
    int freq[26] = {0};
    for(auto s:a){
        freq[s-'a']++;
    }
    for(auto s:b){
        freq[s-'a']++;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        for(char s:c){
            freq[s-'a']--;
            if(freq[s-'a']<0){
                cout<<"NO"<<endl;
                return ;
            }
        }
    }
    cout<<"YES"<<endl;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
