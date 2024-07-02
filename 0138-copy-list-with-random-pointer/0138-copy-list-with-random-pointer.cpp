/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {


public:
    void instail(Node* &copyhead , Node* &copytail , int x){
        if(copyhead == NULL){
            copyhead = new Node(x);
            copytail = copyhead ;
            return;
        }
        Node* temp = new Node(x);
        copytail->next = temp ;
        copytail = temp ;
    }

    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head ;
        Node* copyhead = NULL;
        Node* copytail = NULL;
        while(temp != NULL){
          instail(copyhead,copytail,temp->val);
         temp = temp->next;
        }

        
        temp = head ;
        Node* t;
        Node* c = copyhead;
        Node *cp ;

        while(temp != NULL){
         t = temp->next ;
        temp->next = c ;
        temp = t;
        cp = c->next;
        c->next = t ; 
        c= cp;
        }
       
       temp = head ;
       c = copyhead;
       while(temp != NULL && c != NULL){
        if(temp->random != NULL)
        temp->next->random = temp->random->next;
        else
         temp->next->random = NULL;
         temp = temp->next->next;
       }

     temp = head ;
     c = copyhead ;
     while(temp != NULL && c != NULL){
        temp->next = c->next ;
        temp = temp->next ;
        if(c->next != NULL)
        c->next = temp->next ;
        else
        c->next = NULL;
        c = c->next;
     }

       return copyhead;
    }
};