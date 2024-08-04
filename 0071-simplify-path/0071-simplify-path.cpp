class Solution {
public:
    string simplifyPath(string path) {

        stack<string>store;
        string s = "";
        for(int i = 1 ; i < path.size() ; i++){
            if(path[i] == '/'){
                if(s != "." && s != ".." && s != "")
                store.push(s);
                if(!store.empty() && s == "..") 
                store.pop();
                s = "";
            }
            
            else{
            s+=path[i];
            }
           

        } 
  
                if(!store.empty() && s == "..") store.pop();
                  else if(s != "." && s != "" && s != "..")
            store.push(s);

            if(store.empty()) return "/";

        string ans = "";
        while(!store.empty()){
           if(store.top() != "" )
           ans = "/" + store.top() + ans;
           store.pop();
        }
        return ans;
    }
};