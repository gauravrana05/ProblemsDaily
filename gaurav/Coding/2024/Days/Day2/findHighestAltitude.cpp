#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        vector<int> g;

        g.push_back(0);
        
        int it = 0;
        for(auto i: gain){
            int alt = g[it++] + i;
            mx= max(alt, mx);
            g.push_back(alt);
        }
        return mx;
    }
};