#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for( auto i : operations){
            // if(i == "++X")
            //     ans += int(i[2]);
            // else
            // if(i == "X++")
            //     ans += int(i[0]);
            // else
            // if(i == "--X")
            //     ans -= int(i[2]);
            // else
            // if(i == "X--")
            //     ans -= int(i[0]);
            if(i == "++X" || i == "X++")
                ans++;
            else
            if(i == "--X" || i == "X--")
                ans--;
        }
        return ans;
    }
};