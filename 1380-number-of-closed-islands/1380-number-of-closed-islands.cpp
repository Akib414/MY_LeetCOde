class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
                        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
         int ans = 0 ;
         int n = grid.size() ;
         int m = grid[0].size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0 && vis[i][j] == false){
                    bool flag = true ;
                    queue<pair<int,int>>q ;
                    q.push({i,j});
                    vis[i][j] = true ;
                    while(!q.empty()){
                     auto f = q.front();
                     q.pop();
                     int si = f.first ;
                     int sj = f.second ;
                     if(si == n-1 || sj == m-1 || si == 0 || sj == 0) flag = false;
                     for(auto a : dir){
                        int ci = si + a.first ;
                        int cj = sj + a.second ;
                        
                        if(ci >= 0 && cj >= 0 && ci < n && cj < m &&  grid[ci][cj] == 0 && vis[ci][cj] == false){
                            q.push({ci,cj});
                            vis[ci][cj] = true ;
                        }
                     }
                    }
                    if(flag) ans++ ;
                }      
            }
        }
        return ans ;
    }
};