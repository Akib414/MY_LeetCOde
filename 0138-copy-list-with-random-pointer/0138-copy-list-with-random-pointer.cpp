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
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        map<Node* , Node*>m;
        Node* temp = head ;
        Node* copyhead = NULL;
        Node* copytail = NULL;
        while(temp != NULL){
          instail(copyhead,copytail,temp->val);
         temp = temp->next;
        }
        Node* copy = copyhead ;
        temp = head ;
        while(head != NULL){
            m[head] = copy ;
            head = head->next ;
            copy = copy->next ;
        }
        copy = copyhead ;
        while(copy != NULL){
            copy->random = m[temp->random];
            copy = copy->next ;
            temp = temp->next ;
        }
        return copyhead ;
       
    }
};