                                                                                                          
class Solution {
public:

    int len(ListNode* head,ListNode* &tail){
        int l = 0;
        while(head != NULL){
        l++;
        if(head->next == NULL) tail = head ;
        head = head->next ;
        }
        return l;
    }
    


    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL) return head ;
         ListNode* tail ;
        int l = len(head,tail);
        int mod = k%l ;
        if(mod == 0) return head ;
        ListNode* temp = head ;
        for(int i = 1 ; i <= l-mod-1 ; i++) temp = temp->next ;
        ListNode* ans = temp->next ;
        temp->next = NULL;
        tail->next = head ;
        return ans ;
    }
};