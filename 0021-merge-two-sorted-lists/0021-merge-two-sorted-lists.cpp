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
    void instail(ListNode* &tail,ListNode* &head,int x){
        if(tail==NULL){
            tail = new ListNode(x);
            head = tail ;
        }
        else{
        ListNode* temp = new ListNode(x);
        tail->next = temp;
        tail = temp;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tail = NULL;
        ListNode* head = NULL;
        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
               instail(tail,head,list2->val);
               list2 = list2->next;
            }
            else{
             instail(tail,head,list1->val);
               list1 = list1->next;
            }
        }
        while(list1 != NULL){
            instail(tail,head,list1->val);
            list1 = list1->next;
        }
              while(list2 != NULL){
            instail(tail,head,list2->val);
            list2 = list2->next;
        } 
        return head;
    }
};