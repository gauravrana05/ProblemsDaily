#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include <fstream>

#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout<<endl;
#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debugg(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define debuggg(x,y,z) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl;

#define rep(i,s,e) for(int i = s; i < e; i++)
#define repD(i,s,e) for(int i = s-1;i >= e; i--)

#define repS(i,s,e,step) for(int i = s;i < e;i+=step)
#define repDS(i,s,e,step) for(int i = s-1;i >= e;i-=step)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

#define pr(x) cout<<x<<" "

#define prA(arr, s, e) {for(int i = s;i < e; i++){ cout<<arr[i]<<" ";}cout<<endl;} 
using namespace std;

const int MOD = 1e9 + 7;


int main() {
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

    bint a, b, c;
    bint c_a, c_b, c_c;
    fin>>c_a>>a;
    fin>>c_b>>b;
    fin>>c_c>>c;
    int i = 0;
    // debuggg(a, b, c);
    while(true){
        
        if(a + b < c_b ){
            b = a + b;
            a = 0;
        }
        else{
            a = a - (c_b - b);
            b = c_b;
        }
        i++;
        // debuggg(a, b, c);
        if( i>= 100){
            break;
        }
        if(b + c < c_c){
            c = c + b;
            b = 0;
        }
        else{
            b = b - (c_c - c);
            c = c_c;
        }
        i++;
        // debuggg(a, b, c);
        if(c + a < c_a){
            a = a + c;
            c = 0;
        }
        else{
            c = c - (c_a - a);
            a = c_a;
        }
        i++;
        // debuggg(a, b, c);
    }

    fout<<a<<"\n"<<b<<"\n"<<c<<endl;

    return 0;
}