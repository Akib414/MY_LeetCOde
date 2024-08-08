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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head ;
        ListNode* small = head ;
        ListNode* big = head ;
        ListNode* temp = head ;
        while( small != NULL && small->val >= x)
        small = small->next ;
        if(small == NULL) return head ;
        while(big != NULL && big->val < x )
        big=big->next ;
        if(big  == NULL) return head ;
      ListNode* ans = small ;
      ListNode* bigpart = big ;
        while(temp != NULL){
            if(temp->val < x && temp != small){
                small->next = temp ;
                small = temp ;
            }
            if(temp->val >= x && temp != big){
                big->next = temp ;
                big = temp ;
            }
            temp = temp->next ;
        }
        small->next = bigpart ;
        big->next = NULL;
        return ans ;
    }
};