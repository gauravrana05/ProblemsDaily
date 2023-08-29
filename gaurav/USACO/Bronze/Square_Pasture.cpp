#include<iostream>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Rect {
    int a, b , c, d;
};

int main(){
    ios_base::sync_with_stdio(0);
    setIO("square");
    Rect f, s;

    cin>>f.a>>f.b>>f.c>>f.d;
    cin>>s.a>>s.b>>s.c>>s.d;

    Rect ans;
    ans.a = min(f.a, s.a);
    ans.b = min(f.b, s.b);
    ans.c = max(f.c, s.c);
    ans.d = max(f.d, s.d);

    int mx = max(ans.d - ans.b, ans.c - ans.a);
    cout<<mx * mx<<endl;;
    



    
    return 0;
}