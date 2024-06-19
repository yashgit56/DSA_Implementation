#include<iostream>

using namespace std ;
bool found = false ;

struct Node {
    int data ;
    struct Node *left ;
    struct Node *right ;
};

Node* createNode(int value = 0){
    Node *node = new Node() ;
    node->data = value ;
    node->left = NULL ;
    node->right = NULL ;
    return node ;
}
Node* insert_in_bst(Node * root , Node *node , int key=0){
    Node *temp = root ;
    Node* current  ;
    Node* parent ;
    if(root == NULL){
        root->left = node ;
        return root ;
    }
    else{
        current = root->left ;
        parent = root ;
    }

    while(current != NULL){
        parent = current ;
        if(key < current->data){
            current = current->left ;
        }
        else{
            current = current->right ;
        }
    }
    if(key < parent->data){
        parent->left = node ;
    }
    else{
        parent->right = node ;
    }
    return temp ;
}
Node *insert(Node * root , Node * node , int key= 0){
    Node *parent = NULL ;
    Node * orignal = root ;
    while(root != NULL){
        parent = root ;
        if(key == root->data)
            return NULL ;
        else if(key < root->data)
            root = root->left ;
        else 
            root = root->right ;        
    }
    if(key < parent->data)
        parent->left = node ;
    else
        parent->right = node ;

    return orignal ;        
}

bool search_in_bst(Node *root, int key){
    if(root == NULL && found == false)
        return false ;
    if(root->data == key)
        return true ;
    else if(key > root->data)
        return search_in_bst(root->right,key) ;
    else
        return search_in_bst(root->left,key) ;    
}

void inorder_traversal(Node *root){
    if(root != NULL){
        inorder_traversal(root->left) ;
        cout << root->data << " " ;
        inorder_traversal(root->right) ;
    }
}

int main(){
    // creating all nodes of binary tree 
    Node * p1 = createNode(40) ;
    Node * p2 = createNode(30) ;
    Node * p3 = createNode(50) ;
    Node * p4 = createNode(25) ;
    Node * p5= createNode(35) ;
    Node * p6 = createNode(45) ;
    Node * p7= createNode(60) ;

    // make connections between all binary tree nodes
    p1->left = p2 ;
    p1->right = p3 ;

    p2->left = p4 ;
    p2->right = p5 ;

    p3->left = p6 ;
    p3->right = p7 ;

    int val ;
    cout << "enter which element you want to insert:" ;
    cin >> val ;
    Node *node = createNode(val) ;

    
    Node* final = insert_in_bst(p1,node,val) ;
    inorder_traversal(final) ;

    int search ;
    cout << "enter which node you want to search in a bst:";
    cin >> search ;
    if(search_in_bst(p1,search))
        cout << "node found in bst" << endl ;
    else
        cout << "node not found in bst" << endl ;    




    


    return 0 ;
}