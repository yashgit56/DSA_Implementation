#include <iostream>

using namespace std ;

struct Node{
    int data ;
    struct Node * left ;
    struct Node * right ;
};

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
    traversalRL(last);
}