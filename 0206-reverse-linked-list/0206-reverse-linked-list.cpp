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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head ;
        ListNode* store = NULL ;
        ListNode* temp = head ;
        ListNode* save ;
        while(temp != NULL){
            save = temp->next ;
            temp->next = store ;
            store = temp;
            temp = save ;  
        }
        return store ;
    }
};