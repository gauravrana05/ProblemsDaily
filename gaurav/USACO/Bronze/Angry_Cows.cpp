#include <bits/stdc++.h>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
    int n;
    cin >> n;
    vector<long long int> positions(n);
    for (auto &i : positions)
    {
        cin >> i;
    }

    long long int time = 0;
    long long int blastRadius = 1;

    sort(positions.begin(), positions.end());

    long long count = 1, mCount = 0, i = 0;
    while (i < n)
    {
        time++;
        blastRadius = positions[i] + time;
        i++;
        if (i < n)
        {
            if (positions[i] <= blastRadius)
            {
                while (positions[i] <= blastRadius && i < n)
                {
                    count++;
                    i++;
                }
                i--;
            }
            else
            {
                count = 1;
                time = 0;
                i++;
            }
        }
        mCount = max(count, mCount);
    }

    count = 1;
    i = positions.size() - 1;
    while (i >= 0)
    {
        time++;
        blastRadius = positions[i] - time;
        i--;
        if (i >= 0)
        {

            if (positions[i] >= blastRadius)
            {
                while (positions[i] >= blastRadius && i >= 0)
                {
                    count++;
                    i--;
                }
                i++;
            }
            else
            {
                count = 1;
                time = 0;
                i--;
            }
        }
        mCount = max(count, mCount);
    }

    cout << mCount;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("angry");
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}