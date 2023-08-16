#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n, m, j;
    cin>>n;
    cin>>m;

    multiset<int> s;

    while(n--){
        cin>>j;
        s.insert(j);
    }

    while(m--){
        
        cin>>j;
        auto i = s.upper_bound(j);

        if(i == s.begin()){
            cout<<"-1\n";
        }
        else{
            i--;
            cout<<*i<<endl;
            s.erase(i);
        }
    }


    

    return 0;
}