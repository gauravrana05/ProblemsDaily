#include <iostream>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{

    int n, k;
    cin >> n >> k; // Input
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n); // sort the diamonds

    int l = 0, r = 0, ans = 0, count = 0;
    // two pointers
    while (r < n)
    {
        if (a[r] - a[l] <= k)
        { // if the difference is atmost k
            count++;
            r++;
        }
        else
        {
            while (a[r] - a[l] > k)
            { // if the difference is more than k
                count--;
                l++;
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("diamond");

    solve();
    return 0;
}