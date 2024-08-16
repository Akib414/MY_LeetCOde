class Solution {
public:
    string minWindow(string s, string t) {
       map<char,int>mc;
       for(auto a : t){
        if(mc.find(a) == mc.end()){
            mc[a]=1;
      
        }
        else
        mc[a]++;
       }

    int st = 0 , end = s.size();  
for(int i = 0 ; i < s.size() ; i++){
  if(mc.find(s[i]) != mc.end()){
    st = i ;
    break ;
  } 
}

for(int i = s.size()-1 ; i >= 0 ; i--){
  if(mc.find(s[i]) != mc.end()){
    end = i ;
    break ;
  } 
}

int cnt = 0 ;
int start , finish ;
int comp = INT_MAX ;
string ans = "";
for(int i = st , l = st; i <= end ; i++){
  if(mc.find(s[i]) != mc.end()){
    if(mc[s[i]]>0) cnt++;
      mc[s[i]]--;
      
  }
  while(l<=i && cnt == t.size()){
       if(i-l+1 < comp){
       start = l ;
       finish = i ;
       comp = i-l+1;
       }
      if(mc.find(s[l]) != mc.end()){
       mc[s[l]]++;
       if(mc[s[l]] > 0) cnt--;
      }
      l++;
  }
}

if(comp == INT_MAX) return ans;
for(int i = start ; i <= finish ; i++)
ans+=s[i];
return ans;
    }
};