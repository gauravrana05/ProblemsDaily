#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        vector<int> words;
        int mx = INT_MIN;
        for(auto i: sentences){
            int count = 0;
            for(int j = 0; j < i.length(); j++ ){
                if(i[j]==' ')
                    count++;
            }
            mx = max(mx, count + 1);
        }
        return mx;
    }
};