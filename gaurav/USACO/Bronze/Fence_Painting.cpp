#include<iostream>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios_base::sync_with_stdio(0);
    setIO("paint");
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int paint_x = min(a, c);
    int paint_y = max(b, d);
    cout<< min(paint_y - paint_x,  b - a + d - c)<<endl;
    
    return 0;
}