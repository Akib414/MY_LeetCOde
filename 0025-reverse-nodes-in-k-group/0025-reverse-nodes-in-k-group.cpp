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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* curr = head ;
        ListNode* prev = NULL;
        ListNode* forward;
        int i = 0;
        while(curr != NULL && i<k ){
         forward = curr;
        curr = curr->next ;
        forward->next = prev ;
         prev = forward ;
         i++;
        }
            if(i<k){
            ListNode* curr1 = prev;
            ListNode* next1 = NULL;
            ListNode* prev1 = NULL;
            while(curr1 != NULL){
                next1 = curr1;
                curr1 = curr1->next;
                next1->next  = prev1;
                prev1 = next1;
            }
            return prev1;
          }   
         head->next = reverseKGroup(curr,k);
  
        return prev;  
    }
};