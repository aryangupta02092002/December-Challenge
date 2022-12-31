class Solution {
public:
    int empty = 1, ans = 0;
  
    void dfs(vector<vector<int>>& grid, int start, int end, int count){
      if(start < 0 || start >= grid.size() || end < 0 || end >= grid[0].size() || grid[start][end] == -1)
        return;
      
      if(grid[start][end] == 2){
        if(empty == count)
          ans++;
        return;
      }
      grid[start][end] = -1;
      
      dfs(grid, start+1, end, count+1);
      dfs(grid, start-1, end, count+1);
      dfs(grid, start, end+1, count+1);
      dfs(grid, start, end-1, count+1);
      
      grid[start][end] = 0;
    }
  
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start, end;
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
          if(grid[i][j] == 1){
            start = i, end= j;
          }
          else if(grid[i][j] == 0){
            empty++;
          }
        }
      }
      dfs(grid, start, end, 0);
      return ans;
    }
};
