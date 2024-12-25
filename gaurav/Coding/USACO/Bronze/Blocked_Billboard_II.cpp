#include<iostream>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Rect {
    int a, b, c, d;
};
int area(Rect f){
    int a = f.a, b = f.b, c = f.c , d = f.d;
    return ((d - b)*(c - a));
}

int intersection( Rect f, Rect s){
    int a = f.a, b = f.b, c = f.c , d = f.d;
    int x = s.a, y = s.b, z = s.c, w = s.d;
    return(max(0, min(w, d) - max(y, b)) * max(0, (min(z, c) - max(a , x))));
}

bool isIntersecting(Rect f, Rect s){

    if( f.a > s.c || f.b > s.d || s.a > f.c || s.b > f.d)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    setIO("billboard");
    
   Rect bad, good;
    cin>>bad.a>>bad.b>>bad.c>>bad.d;
    cin>>good.a>>good.b>>good.c>>good.d;

         if(( bad.a >= good.a && bad.c <= good.c)){
            if(bad.b < good.b && bad.d > good.d)
                cout<<area(bad);
            else
                cout<<area(bad) - intersection(good, bad)<<endl;
            }
        else
        if(bad.b >= good.b && bad.d <= good.d){
            if(bad.a < good.a && bad.c > good.c)
                cout<<area(bad);
            else
                cout<<area(bad) - intersection(good, bad)<<endl;
        }
        else
            cout<<area(bad)<<endl;  


    



    
    return 0;
}