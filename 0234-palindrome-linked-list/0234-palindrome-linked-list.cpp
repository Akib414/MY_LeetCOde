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
  void ansify(ListNode* head , ListNode* &temp , int &a){
     if(head == NULL) return ;
     ansify(head->next , temp , a);
     if(head->val != temp->val) a = 1;
     temp = temp->next ;
  }


    bool isPalindrome(ListNode* head) {
        ListNode* temp = head ;
        int a = 0;
         ansify(head,temp,a);
        if(a==1) return false ;
        return true ;
    }
};