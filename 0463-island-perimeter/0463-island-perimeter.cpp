class Solution {
public:
  vector<pair<int,int>>dir = {{0,-1},{0,1},{-1,0},{1,0}};
   void dfs(vector<vector<int>>& grid , int &ans , int si , int sj ,vector<vector<bool>>&vis ){
    vis[si][sj] = true  ;
    for(auto a : dir){
        int ci = si+a.first ;
        int cj = sj+a.second ;
     if(ci >= 0 && cj >= 0 && ci < grid.size() && cj < grid[0].size()){
        if(grid[ci][cj] == 0) ans++ ;
        if(grid[ci][cj] == 1 && !vis[ci][cj]) dfs(grid,ans,ci,cj , vis);
     }
    else
    ans++ ;
    }
    
   }


    int islandPerimeter(vector<vector<int>>& grid) {
        //we will apply dfs here {}
        //the main thing is we will reach to every land square
        //then we will move up,down,left,right with maintaining validity and visited
        //if in all direction we find water or border we add 1 to perimeter 
        int ans = 0 ;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                dfs(grid,ans,i,j , vis);
                break;
                }
            }
        }
       return ans ;
    }
};