int dfs(int** g,int r,int c,int m,int n) {
    if(r<0 || r>=m || c<0|| c>=n) return 0;
    if(g[r][c]==1) return 1;
    g[r][c]=1;
    return dfs(g,r+1,c,m,n) & dfs(g,r-1,c,m,n) &
           dfs(g,r,c+1,m,n) & dfs(g,r,c-1,m,n);
}
int closedIsland(int** grid,int gs,int* gc) {
    int m=gs,n=gc[0],c=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]==0)
                c+=dfs(grid,i,j,m,n);
    return c;
}