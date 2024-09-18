class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
                vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
         int ans = 0 ;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j <grid[0].size() ; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    queue<pair<int,int>>q ;
                    q.push({i,j});
                    vis[i][j] = true ;
                    while(!q.empty()){
                     auto f = q.front();
                     q.pop();
                     int si = f.first ;
                     int sj = f.second ;
                     for(auto a : dir){
                        int ci = si + a.first ;
                        int cj = sj + a.second ;
                        if(ci >= 0 && cj >= 0 && ci < grid.size() && cj < grid[0].size() &&  grid[ci][cj] == '1' && vis[ci][cj] == false){
                            q.push({ci,cj});
                            vis[ci][cj] = true ;
                        }
                     }
                    }
                    ans++ ;
                }
                
            }
        }
        return ans ;
    }
};