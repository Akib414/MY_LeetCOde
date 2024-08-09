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

    ListNode* findmid(ListNode* head){
        ListNode* fast = head->next ;
        ListNode* slow = head ;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        return slow ;
    }
    ListNode* merge(ListNode* left , ListNode* right ){
        ListNode* sorted ;
        if(left->val < right->val){
           sorted = left ;
           left = left->next ;
        }
        else{
            sorted = right ;
            right = right->next ;
        }
   ListNode* ans = sorted ;
       while(left != NULL && right != NULL){
        if(left->val < right->val){
            sorted->next = left ;
             sorted = left ;
            left = left->next ;
           
        }
        else{
            sorted->next = right ;
            sorted = right ;
            right = right->next ;
            
        }
       }
        while(left != NULL){
            sorted->next = left ;
                         sorted = left ;

            left = left->next ;
           
        }
            while(right != NULL){
            sorted->next = right ;
            sorted = right ;
            right = right->next ;
        }
        sorted->next = NULL;
        return ans ;
       }
    

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;
        //dividing into two linked list
        ListNode* mid = findmid(head);
        ListNode* left = head ;
        ListNode* right = mid->next ;
        mid->next = NULL ;
        ListNode* newleft = sortList(left);
        ListNode* newright = sortList(right);
        sortList(right);
        //sorting and merging
        return merge(newleft,newright);
    }
};