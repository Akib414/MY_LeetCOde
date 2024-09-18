class Solution {
public:

   //a vector that that stores the node to node connection of all nodes
    vector<int>ntoe[200005];
  
    bool ans = false  ;
    void bfs(int s , int d ,  vector<bool>&vis){
        queue<int>q ;
        q.push(s);
        vis[s] = true ;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto a : ntoe[f]){
                if(!vis[a]){
                    q.push(a);
                    vis[a] = true ;
                    if(a == d) ans = true ;
                }
            }

        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
          vector<bool>vis(200005,false); 
        if(s == d) return true ;
     for(auto a :edges){
        ntoe[a[0]].push_back(a[1]);
        ntoe[a[1]].push_back(a[0]);
     }
     if(edges.size() == 0) return false ;
     bfs(s,d,vis);
     return ans ;

    }
};