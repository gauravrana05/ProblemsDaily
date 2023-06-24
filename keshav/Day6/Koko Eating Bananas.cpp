class Solution {
public:

    bool check(vector<int>& piles, int h, int mid){
        long long int ans = 0;
        for(int p:piles){
            ans+=(long)(p/mid)+1;
            if(!(p%mid)) ans--;
        }
        return ans<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;

        while(l<=r){
            int mid = (l+r)/2;
            if(check(piles,h,mid)){
                r=mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};