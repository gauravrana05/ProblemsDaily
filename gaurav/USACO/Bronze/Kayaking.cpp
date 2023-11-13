#include <bits/stdc++.h>
using namespace std;

using namespace std;

void solve()
{
    long long n;
    cin >> n;
    set<long long> s;

    for (int i = 0; i< 2 * n; i++)
    {
        int val;
        cin >> val;
        if (s.find(val) != s.end())
        {
            s.erase(val);
        }
        else{
            s.insert(val);
        }
    }
    long long result = INT64_MAX;

    vector<int> w;
    for(auto i: s){
        // cout<<i<<" ";
        w.push_back(i);
    }
    if(s.size() == 2){

        cout<<0<<"\n";
        return;
    }

    for (int i = 0; i < w.size() - 1; i++)
    {

        for (int j = i + 1; j < w.size(); j++)
        {
            // cout<<"choosen pair"<< w[i] << " and "<<w[j]<<endl;
            long long ans = 0;

            for (int k = w.size() - 1; k > 0; k--)
            {
                int first = k, second = k - 1;
                if(k == i || k == j){
                    // cout<<"equal "<<k<<" "<<i<<" "<<j<<endl;
                    continue;
                }
                else if(k - 1 == i || k - 1 == j){
                    // cout<<"second equal "<<k<<" "<<i<<" "<<j<<endl;
                    k--;
                    second--;
                }
               
                ans += w[first] - w[second]; 
                k--;
            }
                // cout<<"This is answer"<<ans<<"\n";
            result = min(result, ans);
            // cout<<"This is result"<<result<<"\n";
        }
    }
    cout<<result<<endl;
}

int main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}