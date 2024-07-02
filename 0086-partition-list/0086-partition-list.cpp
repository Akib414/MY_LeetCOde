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
    void instails(ListNode* &small,ListNode* &stail, int x){
     if(small == NULL){
        small = new ListNode(x);
        stail = small;
        return ;
     }
     ListNode* temp = new ListNode(x);
     stail->next = temp;
     stail = temp;
    }

    void instailb(ListNode* &big,ListNode* &btail, int x){
          if(big == NULL){
        big = new ListNode(x);
        btail = big;
        return ;
     }
     ListNode* temp = new ListNode(x);
     btail->next = temp;
     btail = temp;
    }

public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* small = NULL;
        ListNode* stail = NULL;
        ListNode* big = NULL;
        ListNode* btail = NULL;
        while(head != NULL){
            if(head->val < x)
            instails(small,stail,head->val);
            else
            instailb(big,btail,head->val);
            head = head->next ;
        }
        if(small == NULL) return big;
        stail->next = big;
        return small;
    }
};