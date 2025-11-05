class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
        long long n=piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int ans=high;
        while(low<=high){
            long long mid=(low+high)/2;
           // int totalhr=fun(piles,h,mid);
            if(fun(piles,h,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    long long fun(vector<int>& piles, int h, int mid ){
        long long totalhr=0;
        for(int i=0; i<piles.size(); i++){
            totalhr += (piles[i]+mid-1)/mid;
        }
        return totalhr;
    }
};