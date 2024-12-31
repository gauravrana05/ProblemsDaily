#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<set>

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

#define rep(i,s,e) for(bint i = s; i < e; i++)
#define repD(i,s,e) for(bint i = s-1;i >= e; i--)

#define repS(i,s,e,step) for(bint i = s;i < e;i+=step)
#define repDS(i,s,e,step) for(bint i = s-1;i >= e;i-=step)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

#define pr(x) cout<<x<<" "

#define prA(arr, s, e) {for(bint i = s;i < e; i++){ cout<<arr[i]<<" ";}cout<<endl;} 
using namespace std;

bint max(bint a, bint b){
    if( a > b)
        return a;
    return b;
}
struct Sider{
    bint a, b, c, d;
    bint  area () {return (max(0, (d - b))* max(0, (c - a)));}
    void iter(){
        cout<<"Start (a, b) : "<<a<<" "<<b<<endl;
        cout<<"End (c, d) : "<<c<<" " <<d<<endl;
    }
};

Sider intersection( Sider f, Sider s){
    Sider ret;
    bint a = f.a, b = f.b, c = f.c , d = f.d;
    bint x = s.a, y = s.b, z = s.c, w = s.d;
    ret.a = max(a, x);
    ret.b = max(y, b);
    ret.c = min(z, c);
    ret.d = min(w, d); 
    
    // bint area = (max(0, min(w, d) - max(y, b)) * max(0, (min(z, c) - max(a , x))));
    return ret;
}


int main(){
    Sider w, b1, b2;
    cin>>w.a>>w.b>>w.c>>w.d;
    cin>>b1.a>>b1.b>>b1.c>>b1.d;
    cin>>b2.a>>b2.b>>b2.c>>b2.d;


    Sider i1 = intersection(w, b1);
    // w.iter();
    // debug(w.area());
    // i1.iter();
    Sider i2 = intersection(w, b2);
    // debuggg(w.area(), i1.area(), i2.area());
    // debug(intersection(i1, i2).area());
    if( w.area() -  i1.area() - i2.area() + intersection(i1, i2).area()){
        cout<<"YES"<<endl;
    }
    else    
        cout<<"NO"<<endl;;

    return 0;
}