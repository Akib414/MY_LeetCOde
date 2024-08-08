class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       long long int sum = 0;
        int a = 0 ;
        int i = 0;
        int curr = 0;
        
while(curr<gas.size()){
    if(a==1 && curr == i) return curr ;
    sum = sum + gas[i] - cost[i];
    if(sum < 0){
       sum = 0 ;
        if(a==0 ){
            curr = i+1 ;
        }
        if(a==1) break ;
    }
    i++;
    if(a==0 && i==gas.size()){
        i = 0 ;
        a = 1 ;
    }

}
return -1;
      
       
    }
};