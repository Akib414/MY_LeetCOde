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
     void instail( Node* &copyhead, Node* &copytail , int n){
     if(copyhead == NULL){
        copyhead = new Node(n);
        copytail = copyhead ;
        return ;
     }
     Node* temp = new Node(n);
     copytail->next = temp ;
     copytail = temp ;
     }


    Node* copyRandomList(Node* head) {
   Node* temp = head ;
   Node* copyhead = NULL;
   Node* copytail = NULL;

   while(temp != NULL){
   instail(copyhead , copytail , temp->val);
   temp = temp->next ;
   }
temp = head ;
Node* copy = copyhead ;
while(temp != NULL && copy != NULL){
    Node* store = temp->next ;
    Node* save = copy->next ;
    temp->next =  copy ;
    copy->next = store ;
    temp = store ;
    copy = save ;
}
temp  = head ;
while(temp != NULL){
    if(temp->random != NULL)
    temp->next->random  = temp->random->next ;
    else
    temp->next->random  = NULL ;
    temp = temp->next->next ; 
}
temp = head ;
copy = copyhead ;
while(temp != NULL && copy != NULL){
    Node* store ;
    if(temp->next->next != NULL)
store = temp->next->next->next ;
    else
    store = NULL ;
    temp->next = temp->next->next ;
    copy->next = store ;
    temp = temp->next ;
    copy = copy->next ;
}
return copyhead ;

    }
};