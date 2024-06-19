#include <iostream>

using namespace std ;
struct Node {
    int data ;
    struct Node *next ;
};
Node * insertion_at_end(Node *last , int value){
    Node *temp = new Node() ;
        temp->data = value ;
        last->next = temp ;
        temp->next = NULL ;
        last = temp ;
        return last ;
}
Node * deletion_at_end(Node *head){
    Node *p = head , *q = head->next ;

    while(q->next != NULL){
        p = p->next ;
        q = q->next ;
    }
    p->next = NULL ;
    return head ;
    
}
Node *deletion_at_beginning(Node * head){
    head = head->next ;
    return head ;
}
Node *delete_specific_node(Node * head , int value){
    Node *p = head , *q = head->next ;
    
    while(q->data != value && q != NULL){
        p = p->next ;
        q = q->next ;
    }
    if(q != NULL){
        p->next = q->next ;
        return head ;
    }
    else 
        cout << "element not found" << endl ;

}
void LLtraversal(Node *head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }
    cout << endl ;
}

int main() {
    // now we are creating a linked list from array

    int n ;
    cout << "enter the size of the array:" ;
    cin >> n ;

    int arr[n] ;
    cout << "now enter the element one by one :" << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    // way to insert element at the end 
    Node *head , *last ;
    head = new Node() ;
    head->data = arr[0] ;
    head->next = NULL ;
    last = head ;

    for(int i = 1 ; i < n ; i++){
        last = insertion_at_end(last , arr[i]) ;
    }
    // way to delete element at the beginning
    
    /*head = deletion_at_beginning(head) ;
    // traversing singly linked list
    LLtraversal(head);
    head = deletion_at_end(head) ;
    LLtraversal(head) ;*/

    // delete node from LL with specific value 
    int value ;
    cout << "enter the value of the node : " ;
    cin >> value ;

    head = delete_specific_node(head,value) ;
    LLtraversal(head) ;

}