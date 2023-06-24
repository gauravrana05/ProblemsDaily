class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
       for(int i=0;i<intervals.size();i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> &v=ans.back();
                if(intervals[i][0]<=v[1])
                {
                    v[1]=max(intervals[i][1],v[1]);
                }
                else
                    ans.push_back(intervals[i]); 
            }
        }
        return ans;
    } 
};
