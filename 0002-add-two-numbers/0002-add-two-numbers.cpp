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
     void instail(ListNode* &head , ListNode* & tail , int x){
        if(tail == NULL){
            tail = new ListNode(x);
            head = tail ;
            return;
        }
        ListNode* temp = new ListNode(x);
        tail->next = temp ;
        tail = temp;
    
     }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 != NULL && l2 != NULL){
            int total = l1->val + l2->val + extra;
            int ld = total%10;
             instail(head,tail,ld);
             extra = total/10;
                if(l1->next == NULL &&  l2->next == NULL && extra != 0){
                instail(head,tail,extra);
            }
             l1 = l1->next;
             l2 = l2->next;

        }
        while(l1 != NULL){
            int total = l1->val + extra ;
            int ld = total%10;
            instail(head,tail,ld);
            extra = total/10;
            if(l1->next == NULL && extra != 0){
                instail(head,tail,extra);
            }
            l1 = l1->next;

        }
               while(l2 != NULL){
            int total = l2->val + extra ;
            int ld = total%10;
            instail(head,tail,ld);
            extra = total/10;
                 if(l2->next == NULL && extra != 0){
                instail(head,tail,extra);
            }
            l2 = l2->next;
        }
        return head;

    }
};