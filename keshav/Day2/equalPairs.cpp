class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        int n = grid.size();
        for(int i=0;i<n;i++){
            m[grid[i]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            ans+=m[temp];
        }
        return ans;
    }
};