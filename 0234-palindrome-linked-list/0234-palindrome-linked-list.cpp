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
    ListNode* reverse(ListNode* mid){
        ListNode* prev = NULL;
        ListNode* curr= mid;
        while(curr != NULL){
            ListNode* forward = curr;
            curr = curr->next ;
            forward->next = prev;
            prev = forward;
        }
        return prev;
    }
    ListNode* fm(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
      ListNode* middle = fm(head);
   
      ListNode* m =    reverse(middle->next);
      while(m != NULL){
        if(head->val != m->val) return false;
        m = m->next;
        head = head->next;
      }
      return true;
    }
};