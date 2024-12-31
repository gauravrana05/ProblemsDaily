#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        switch (s[0])
        {
        case '1':
            cout<<13;
            break;
        case '2':
            cout<<23;
            break;
        case '3':
            cout<<31;
            break;
        case '4':
            cout<<41;
            break;
        case '5':
            cout<<53;
            break;
        case '6':
            cout<<61;
            break;
        case '7':
            cout<<71;
            break;
        case '8':
            cout<<83;
            break;
        case '9':
            cout<<97;
            break;
        
        default:
            break;
        }
        cout<<endl;
    }
}