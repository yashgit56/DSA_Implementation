#include <iostream>

using namespace std ;

struct Node{
    int data ;
    struct Node * left ;
    struct Node * right ;
};
Node *insert_at_front(Node *head , int value){
    Node *node = new Node() ;
    node->data = value ;
    node->left = NULL ;
    node->right = head ;
    head->left = node ;
    head = node ;
    return head ;
}
Node * insert_at_given_index(Node *head , int index , int value){
    Node *node = new Node() ;
    node->data = value ;
    int count = 0 ;

    while(count != index - 2){
        head = head->right ;
        count++ ;
    }
    node->right = head->right ;
    head->right = node ;
    node->left = head ;
    head->right->left = node ;
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
int  find_element_index(Node *head,int element){
    int count = 1 ;
    while(head->data != element && head->right != NULL){
        head = head->right ;
        count++ ;
    }
    if(head->right == NULL && head->data != element){
        cout << "element not found in list" << endl ;
        return -1 ;
    }
    else    
        return count ;

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
    
    // inserting element at the front of the doubly linked list

    int front ;
    cout << "enter the element which you want to insert at the front:";
    cin >> front ;

     head = insert_at_front(head , front);
    // traversalLR(head);

    // inseting element at a given index
    // int index , element ;
    // cout << "insert index and element which you want to insert:" ;
    // cin >> index >> element ;

    // head = insert_at_given_index(head , index , element);
    // traversalLR(head); 

    // finding given element is present at which index
    int find_element ;
    cin >> find_element ;

    int pos = find_element_index(head, find_element);
    cout << pos << endl ; 

    


}