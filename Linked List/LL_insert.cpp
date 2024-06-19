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
Node *insertion_at_beginning(Node * head , int value){
    Node *temp ;
    temp->data = value ;
    temp->next = head ;
    head = temp ;
    return head ;
}
Node *insertion_at_given_index(Node * head ,int index , int value){
    int count = 0 ;
    Node *node , *temp = head ;
    while(count != index-2){
        temp = temp->next ;
        count++ ;
    }
    node->data = value ;
    node->next = temp->next ;
    temp->next = node ;
    return head  ;
}
void LLtraversal(Node *head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }

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
    // way to insert element at the beginning
    int element ;
    cout << "enter element which you want to insert at the front:" ;
    cin >> element ;
    Node *first ; 
    first = insertion_at_beginning(head , element);
    head = first  ;
    LLtraversal(head) ;
    cout << endl ;
    // insert element at random index ;
    int ele , index ;
    cout << "insert index and element you want to insert : " ;
    cin >> index  >> ele ;

    head = insertion_at_given_index(head , index , ele);
    // traversing singly linked list
    LLtraversal(head);
}