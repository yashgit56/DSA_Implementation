#include<iostream>

using namespace std ;

struct Node {
    int data ;
    struct Node *left ;
    struct Node *right ;
};

Node * create_node(int value) {
    Node *node = new Node() ;
    node->data = value ;
    node->left = NULL ;
    node->right = NULL ;
    return node ;
}

bool search_in_bst(Node *root , int key){
    while(root != NULL){
        if(key > root->data)
            root = root->right ;
        else if(key < root->data)
            root = root->left ;
        else
            return true ;        
    }
    return false ;


}

int main(){
    // creating all nodes of binary tree 
    Node * p1 = create_node(40) ;
    Node * p2 = create_node(30) ;
    Node * p3 = create_node(50) ;
    Node * p4 = create_node(25) ;
    Node * p5= create_node(35) ;
    Node * p6 = create_node(45) ;
    Node * p7= create_node(60) ;

    // make connections between all binary tree nodes
    p1->left = p2 ;
    p1->right = p3 ;

    p2->left = p4 ;
    p2->right = p5 ;

    p3->left = p6 ;
    p3->right = p7 ;

    int key ;
    cout << "enter which element you want to find:" ;
    cin >> key ;
    bool idx = search_in_bst(p1,key) ;
    
    if(idx)
        cout << "element is found in BST" ;
    else
        cout << "elment is not found" ;    


    return 0 ;
}