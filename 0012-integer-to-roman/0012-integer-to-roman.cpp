class Solution {
public:
 
 
     void rom(string &s,int num , int i){
        if(num==0) return ;
        int ld = num%10;
        rom(s,num/10,i+1);
        if(i==3){
            for(int j = 1 ; j<=ld; j++)
            s+="M";
        }


        else if(i==2 && ld >=5 && ld<9){
            for(int j = 5 ; j<=ld ; j++){
                if(j==5) s+="D";
                else s+="C";
            } 
        }
        else if(i==2 && ld==9) s+="CM";

            else if(i==2 && ld <4 && ld>=1){
            for(int j = ld ; j>=1 ; j--)
              s+="C";
            
        }
        else if(i==2 && ld==4) s+="CD";


        else if(i==1 && ld>=5 && ld<9){
            for(int j = 5; j<=ld ; j++){
                if(j==5) s+="L";
                else s+="X";
            }
        }
        else if(i==1 && ld==9) s+="XC";

                    else if(i==1 && ld <4 && ld>=1){
            for(int j = ld ; j>=1 ; j--)
              s+="X";
            
        }
        else if(i==1 && ld==4) s+="XL";


           else if(i==0 && ld>=5 && ld<9){
            for(int j = 5; j<=ld ; j++){
                if(j==5) s+="V";
                else s+="I";
            }
        }
        else if(i==0 && ld==9) s+="IX";

                    else if(i==0 && ld <4 && ld>=1){
            for(int j = ld ; j>=1 ; j--)
              s+="I";
            
        }
        else if(i==0 && ld==4) s+="IV";


       
     }
    string intToRoman(int num) {
         string s;
         int i = 0;
         rom(s,num,i);
         return s;
    }
};