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

      ListNode* fm(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow;
      }

      void instail(ListNode* &ans , ListNode* &tail , int x){
        if(tail == NULL){
            ans = new ListNode(x);
            tail = ans;
            return;
        }
        ListNode* temp = new ListNode(x);
        tail->next = temp ;
        tail = temp ;
      }


      ListNode* merge(ListNode* first , ListNode* second){
        if(first == NULL) return second ;
        if(second == NULL) return first;
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        while(first != NULL && second != NULL){
            if(first->val < second->val){
              instail(ans,tail,first->val);
              first = first->next ;
            }
            else{
            instail(ans,tail,second->val);
              second = second->next ;
            }
        }
        while(first != NULL){
               instail(ans,tail,first->val);
              first = first->next ;
        }
        while(second != NULL){
              instail(ans,tail,second->val);
              second = second->next ; 
        }
        return ans;
      }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
       ListNode* mid = fm(head);
       ListNode* temp = mid->next ;
       mid->next = NULL;
       ListNode* first = sortList(head) ;
       ListNode* second = sortList(temp);

       ListNode * ans = merge(first,second);
       return  ans;
    }
};