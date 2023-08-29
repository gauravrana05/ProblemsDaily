#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
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
void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
    vector<string> s(3);
    cin >> s[0];
    cin >> s[1];
    cin >> s[2];
    int a_1 = 0, a_2 = 0;

    set<char> container;
    set<set<char> > coc[3];

    rep(i, 0, 3)
    {
        container.clear();
        container.insert(s[i][0]);
        container.insert(s[i][1]);
        container.insert(s[i][2]);

        coc[container.size() - 1].insert(container);
    }
    rep(i, 0, 3)
    {
        container.clear();
        container.insert(s[0][i]);
        container.insert(s[1][i]);
        container.insert(s[2][i]);

        coc[container.size() - 1].insert(container);
    }

    container.clear();
    container.insert(s[0][0]);
    container.insert(s[1][1]);
    container.insert(s[2][2]);
    coc[container.size() - 1].insert(container);

    container.clear();
    container.insert(s[2][0]);
    container.insert(s[1][1]);
    container.insert(s[0][2]);
    coc[container.size() - 1].insert(container);

    cout << coc[0].size()<<endl<<coc[1].size()<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("tttt");

    solve();
    return 0;
}