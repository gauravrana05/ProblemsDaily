#include<iostream>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int area(int a, int b, int c, int d){
    return ((d - b)*(c - a));
}

int intersection(int a, int b, int c, int d, int x, int y, int z, int w){
    return(max(0, min(w, d) - max(y, b)) * max(0, (min(z, c) - max(a , x))));
}

int main(){
    ios_base::sync_with_stdio(0);
    setIO("billboard");

    int f1_x1, f1_x2, f2_x1, f2_x2, f1_y1, f1_y2, f2_y1, f2_y2, a, b, c, d;
    cin>>f1_x1>>f1_y1>>f1_x2>>f1_y2;
    cin>> f2_x1>>f2_y1>>f2_x2>>f2_y2;
    cin>>a>>b>>c>>d;
    int ans = 0;
    ans += area(f1_x1, f1_y1, f1_x2, f1_y2);
    ans += area(f2_x1, f2_y1, f2_x2, f2_y2);

    ans -= intersection(f1_x1, f1_y1, f1_x2, f1_y2, a, b, c ,d);
    ans -= intersection(f2_x1, f2_y1, f2_x2, f2_y2,a, b, c, d);

    cout<<ans<<endl;



    
    return 0;
}