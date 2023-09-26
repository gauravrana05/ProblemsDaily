#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;
void solve(int n){
    int x[n];
    int y[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    for (int  i = 0; i < n; i++)
    {
        cin>>y[i];
    }
    double ans = (double)0;
    for (int  i = 0; i < n - 1; i++)
    {
        for (int  j = i + 1; j < n; j++)
        {
            ans = max(ans, (pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2)));
        }
        
    }
    
    cout<<ans<<endl;


}
int main()
{
    cout<<fixed<<setprecision(0);
    int t;
    cin >> t;
        solve(t);
    return 0;
}