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

Node * reverseLL(Node *head){
    Node *current = head , *prev = NULL , *next ;

    while(current != NULL){
        next = current->next ;
        current->next = prev ;
        prev = current ;
        current = next ;
    }
    head = prev ;
    return head ;

}

void LLtraversal(Node *head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }

}

int main() {
    
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
    
     head = reverseLL(head) ;

    LLtraversal(head);
}