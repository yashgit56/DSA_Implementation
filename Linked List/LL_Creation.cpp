#include <iostream>

using namespace std ;
struct  Node {
    int data ;
    struct Node *next ;
};

void array_to_LL(int arr[] , int n){
    Node *head , *last ;
    head = new Node() ;
    head->data = arr[0] ;
    head->next = NULL ;
    last = head ;

    for(int i = 1 ; i < n ; i++){
        Node *temp = new Node() ;
        temp->data = arr[i] ;
        last->next = temp ;
        temp->next = NULL ;
        last = temp ;
    }

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
    array_to_LL(arr , n) ;
}