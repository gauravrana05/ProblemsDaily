#include<iostream>
#include<iomanip>

#define inf int(1e9)
using namespace std;

void solve(){

    int W, H, x1, y1, x2, y2, w, h;

    
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
    int ans = inf;
   
    if (x2 - x1 + w <= W) {
		ans = min(ans, max(0, w - x1));
		ans = min(ans, max(0, x2 - (W - w)));
	}
	if (y2 - y1 + h <= H) {
		ans = min(ans, max(0, h - y1));
		ans = min(ans, max(0, y2 - (H - h)));
	}
    if(ans == inf){
        cout<< -1;
    }
    else{
        cout<<(double)ans;
    }
    cout<<endl;
}
int main(){
      ios_base::sync_with_stdio(0);
      cout << fixed << setprecision(9);
      int t;
      cin>>t;
      while(t--)
        solve();   
    return 0;
}




    // if((W -( x2 - x1) < w ) && (H - (y2 - y1) < h)){
    //     // pr("bs")
    //     ans = -1;
    // }
    // else if(W - (x2 - x1) >= w){
    //     if( max(H - y2, y1) >= h)
    //         ans = 0;
    //     else
    //         ans += max((bint)0, w - max(W - x2, x1));

    // }
    // else if(H - (y2 - y1) >= h){
        
    //     if(max(W - x2, x1) >= w)
    //         ans = 0;
    //     else
    //         ans += max((bint)0,h - max(H - y2, y1));

    // }
    // else{
    //     // debugg(max(H - y2, y1),max( W - x2, x1));
    //     if(max(H - y2, y1) < h && max( W - x2, x1) < w){
    //         ans += h - max(H - y2, y1);
    //         ans += w - max(W - x2, x1);
    //         // pr("rtwo")
    //         // debug(ans);
    //     }
    //     else if(max(H - y2, y1) >= h && max( W - x2, x1) >= w){
    //         ans = 0;
    //     }

    //     else if(max(H - y2, y1) < h ){
    //         ans += h - max(H - y2, y1);
    //         // pr("me")
    //         // debug(ans);
    //     }
    //     else{
    //          ans += w - max(W - x2, x1);
    //         //  pr("you")
    //         //  debug(ans);
    //     }
    // }
    //     cout<<(double)ans;
