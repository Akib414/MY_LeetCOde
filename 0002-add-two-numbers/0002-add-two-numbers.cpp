/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//   int rec(ListNode* l1 , ListNode* l2){
      
      
//   }

     void instail(ListNode* &hd , ListNode* &tl , int n){
        
        if(hd == NULL){
            hd = new ListNode(n);
            tl = hd ;
            return ;
        }
        ListNode* temp = new ListNode(n);
        tl->next = temp;
        tl = temp;
     }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* hd = NULL;
       ListNode* tl = NULL ;
       int rem = 0;
       while(l1 != NULL && l2 != NULL){
            int sum =rem + l1->val + l2->val ;
            rem = sum/10 ;
            instail(hd,tl,sum%10);
            l1 = l1->next ;
            l2 = l2->next;

       }
              while(l1 != NULL){
            int sum =rem + l1->val ;
            rem = sum/10 ;
            instail(hd,tl,sum%10);
            l1 = l1->next ;
           

       }
              while( l2 != NULL){
            int sum =rem + l2->val ;
            rem = sum/10 ;
            instail(hd,tl,sum%10);
            l2 = l2->next;
       }
       if(rem != 0) instail(hd,tl,rem);
return hd ;
       
    }
};