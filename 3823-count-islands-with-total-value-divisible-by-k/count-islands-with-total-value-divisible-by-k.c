static long long dfs(int** grid, int m, int n, int r, int c) {
    long long t=grid[r][c];
    grid[r][c]=0;
    if(r>0 && grid[r-1][c]>0) t+=dfs(grid,m,n,r-1,c);
    if(r+1<m && grid[r+1][c]>0) t+=dfs(grid,m,n,r+1,c);
    if(c>0 && grid[r][c-1]>0) t+=dfs(grid,m,n,r,c-1);
    if(c+1<n && grid[r][c+1]>0) t+=dfs(grid,m,n,r,c+1);   
    return t;
}
int countIslands(int** grid,int gs,int* gc,int k) {
    int m=gs;
    int n=gc[0];
    int c=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]>0)
                if(dfs(grid,m,n,i,j)%k==0)
                    c++;        
    return c;
}