class Solution {
public:
    string intToRoman(int num) {
        string ans = "" ;
        while(num>0){
            


            if(num/1000 > 0){
                int ld = num/1000;
             for(int i = 0 ; i<ld ;i++)
             ans+="M";
             num = num%1000;
            }


            else if(num/100 > 0){
                   int ld = num/100;
                if(ld == 4) ans+="CD";
                else if(ld == 9) ans+="CM";
                else if(ld>=5) ans+="D";
                if(ld != 4 && ld != 9){
                    for(int i = 1 ; i<=ld%5 ; i++)
                    ans+="C";
                }
                num =num%100;
            }

            else if(num/10 > 0){
                   int ld = num/10;
                if(ld == 4) ans+="XL";
                else if(ld == 9) ans+="XC";
                else if(ld>=5) ans+="L";
                if(ld != 4 && ld != 9){
                    for(int i = 1 ; i<=ld%5 ; i++)
                    ans+="X";
                }
                num = num % 10 ;
            }

            else if(num/1 > 0){
                   int ld = num/1;
                if(ld == 4) ans+="IV";
                else if(ld == 9) ans+="IX";
                else if(ld>=5) ans+="V";
                if(ld != 4 && ld != 9){
                    for(int i = 1 ; i<=ld%5 ; i++)
                    ans+="I";
                }
                num = num % 1; 
                
            }
           
        }
        return ans;
    }
};