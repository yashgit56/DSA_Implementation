#include <iostream>

using namespace std ;

struct Node{
    int data ;
    struct Node * left ;
    struct Node * right ;
};
Node *deletion_at_front(Node *head){
    Node *first = head ;
    head = head->right ;
    delete first ;
    return head ;
}
Node *deletion_at_end(Node *head){
    Node *temp = head ;
    while(temp->right->right != NULL){
        temp = temp->right ;
    }
    temp->right = NULL ;
    return head ;
}

Node* delete_specific_node(Node *head , int value){
    Node *q = head ;

    // if(q->right == NULL){
    //     if(q->data == value){
    //         q->right == NULL ;
    //     }
    // }

    while(q != NULL){
        if(value == head->data ){
            Node *temp = q ;
            q = q->right ;
            delete q ;
        }
        else if(q->data == value){
            q->left->right = q->right ;
            q->right->left = q->left ;
        }
        q = q->right ;
    }
    return head ;
}

Node * insert_at_end(Node *last, int value){
    Node *node = new Node() ;
    node->data = value ;
    last->right = node ;
    node->left = last ;
    node->right = NULL ; 

    last = node ;
    return last ; 
}
void traversalLR(Node *head){
    while(head != NULL){
        cout  << head->data << " " ;
        head = head->right ;
    }
    cout << endl ;
}
void traversalRL(Node *last){
    while(last != NULL){
        cout << last->data << " " ;
        last = last->left ;
    }
    cout << endl ;
}
int main() {
    int n ;
    cout << "enter array size:" ;
    cin >> n ;

    int num[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> num[i] ;
    }
    
    Node  *head = new Node() ;
    Node *last = new Node() ;
    head->data = num[0] ;
    head->left = NULL ;
    head->right = NULL ;
    last = head ;

    for(int i = 1 ; i < n ; i++){
        last = insert_at_end(last , num[i]);
    }
    // traversal from left to right
    traversalLR(head) ;
    //traversal from right to left
    // traversalRL(last);

    // deleting element from the front

    // head = deletion_at_front(head) ;
    // traversalLR(head) ;

    // deleting element from the end of the list
    // head = deletion_at_end(head) ;
    // traversalLR(head);

    // delete element  from the list which have a specific value

    int element ;
    cout << "which element you want to delete:" ;
    cin >> element ;
    head = delete_specific_node(head,element);
    traversalLR(head);

    
}