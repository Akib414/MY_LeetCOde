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
int lenght(ListNode* head ){
    int l = 0;
    while(head!= NULL){
        l++;
        head = head->next ;
    }
    return l;
}

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
         int l = lenght(head);
         if(k%l == 0) return head ;
         int c =l - k%l;
         ListNode* first = head ;
         while(c--){
            if(c==0){
                ListNode* temp = head->next ;
                head->next = NULL;
                head = temp ;

            }
            else
             head = head->next ;
         }
         ListNode* ans = head ;
         while(head->next != NULL){
            head = head->next;
         }
         head->next = first;
      return ans;

    }
};