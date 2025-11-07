class Solution {
public:
    void getCombination(int start,vector<int>& num,vector<vector<int>>& ans,int n,int k){
        if(num.size()==k){
            ans.push_back({num});
            return;
        }
        for(int i=start;i<=n;i++){
            num.push_back(i);
            getCombination(i+1,num,ans,n,k);
            num.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> num;
        getCombination(1,num,ans,n,k);
        return ans;
    }
};