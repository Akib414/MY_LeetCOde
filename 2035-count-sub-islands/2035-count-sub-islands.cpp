class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0 ;
        vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    bool flag = true ;
                    queue<pair<int,int>>q ;
                    q.push({i,j});
                    vis[i][j] = true ;
                    while(!q.empty()){
                        auto f = q.front();
                         q.pop();
                        int si = f.first ;
                        int sj = f.second;
                       
                        if(grid1[si][sj] == 0) flag = false ;
                        for(auto a : dir){
                            int ci = si + a.first ;
                            int cj = sj + a.second ;
                            if(ci >= 0 && cj >= 0 && ci < n && cj < m && grid2[ci][cj] == 1 && !vis[ci][cj]){
                             q.push({ci,cj});
                             vis[ci][cj] = true ;
                            }
                        }

                    }
                    if(flag) cnt++ ;
                }
            }
        }
        return cnt ;
    }
};