class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
              int bal = 0;
              int front = 0;
              int rear = 0;
              int n = gas.size();
              int j = 0;
       
              while(front < n){
                bal = bal + gas[rear] - cost[rear];
                
                if(bal < 0) {
                    
                   if(rear < front) return -1;
                   else {
                    front = rear+1;
                    rear = front ;
                    j=0;
                    bal = 0;
                   }

                }
                else{
                    if(rear == n-1) rear = 0;
                    else rear++;
                      j++;
                       if(rear == front && j==n){
                    return front;
                    break;   
                       }
                }
              }
                return -1;  
    }
};