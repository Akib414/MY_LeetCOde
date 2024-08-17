class Solution {
public:
      bool if_possible(int r ,int i ,vector<string>&output ,vector<int>&ocup ,int n){
if(r == 0) return true ;
// else if(find(ocup.begin(),ocup.end(),i)==ocup.end()){

          int j = i;
          int k = r;
             while(k>=0){
                if(output[k--][j] == 'Q') return false ;
             }
             j = i ;
             k = r ;
            while(k>=0 && j<n){
                if(output[k--][j++] == 'Q') return false ;
            }
            j = i;
            k = r;
            while(k>=0 && j>=0){
                if(output[k--][j--] == 'Q') return false ;
            }
// }
      return true ;
      }

void solve(int r , int n,vector<string>&output ,vector<int>&ocup,vector<vector<string>>&ans){
    if(r == n){
        ans.push_back(output);
        return ;
    }
    for(int i = 0 ; i < n ;i++){
        if(if_possible(r,i,output,ocup,n)){
            output[r][i] = 'Q';
            solve(r+1,n ,output ,ocup, ans);
            output[r][i] = '.';
        } 
    }
}
   

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans={};
      vector<string>output(n,string(n,'.'));
      vector<int>ocup ;
      solve(0,n,output,ocup ,ans ) ; 
      return ans;
    }
};