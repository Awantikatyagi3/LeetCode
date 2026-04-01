class Solution {
private:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i-1,j,n,m,grid);
        dfs(i+1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i,j+1,n,m,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1'){
                    dfs(row,col,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};