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
    private:
    void rev(ListNode* &head , ListNode* curr , ListNode* prev){
        if(curr == NULL){
            head = prev ;
            return ;
        }
        rev(head,curr->next,curr);
        curr->next = prev;

    }
public:
    ListNode* reverseList(ListNode* head) {
          ListNode* curr = head ;
          ListNode* prev = NULL;
          rev(head, curr , prev);
          return head;
    }
    
};