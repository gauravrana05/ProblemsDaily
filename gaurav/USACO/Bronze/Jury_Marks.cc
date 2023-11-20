#include <bits/stdc++.h>

#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout << endl;
#define debug(x) cout << #x << " : " << x << endl;
#define debugg(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl;
#define debuggg(x, y, z) cout << #x << " : " << x << " " << #y << " : " << y << " " << #z << " : " << z << endl;

#define rep(i, s, e) for (int i = s; i < e; i++)
#define repD(i, s, e) for (int i = s - 1; i >= e; i--)

#define repS(i, s, e, step) for (int i = s; i < e; i += step)
#define repDS(i, s, e, step) for (int i = s - 1; i >= e; i -= step)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pr(x) cout << x << " "

#define prA(arr, s, e)              \
    {                               \
        for (int i = s; i < e; i++) \
        {                           \
            cout << arr[i] << " ";  \
        }                           \
        cout << endl;               \
    }
using namespace std;

void solve()
{
    int n, k;
    cin >> k >> n;
    vector<int> points(k + 1);
    vector<int> rem(n);

    rep(i, 1, k + 1){
        cin>>points[i];
        points[i] += points[i-1];
    }

    for (auto &i : rem){
        cin >> i;
    }

    set<int> s;


    set<int> poly;
    for (auto &i : points)
    {
        poly.insert(i);
    }

    set<int> values;


        for (int j = 1; j < k + 1 ; j++)
        {
            int val = rem[0] - points[j];
            values.insert(val);
        }

    for( auto val : values){
       
        set<int> possible;
        for( int u=1; u<=k; u++){
            possible.insert(val+ points[u]);
        }

        bool flag = true;
       
        for( auto p: rem){
            flag &= possible.count(p);
        }
             if (flag)
            {
                s.insert(val);
            }
    }

    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}