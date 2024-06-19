#include <bits/stdc++.h>

using namespace std ;

class BST {
        int data ;
        BST * left , *right ;
    public:
        BST(int value = 0) {
            data = value ;
            left = NULL ;
            right = NULL ;
        }
        BST * insert(BST *root, int value){
            BST *node = new BST(value) ;

            if(root == NULL)
                return node ;

            BST *parent = NULL , *current = root ;

            while(current != NULL){
                parent = current ;

                if(value < current->data){
                    parent = current ;
                    current = current->left ;
                }
                else if(value > current->data){
                    parent = current ;
                    current = current->right ;
                }
                else{
                    cout << "Node containing value " << value << "already exist in BST" << endl ;
                    return NULL ;
                }
            }
            if(value > parent->data){
                parent->right = node ;
            }
            else{
                parent->left = node ;
            }   
        }

        void inorder_recursive(BST * root){
            BST *temp = root ;

            if(temp != NULL){
                inorder(root->left) ;
                cout << root->data << " " ;
                inorder(root->right) ;
            }
        }
        void inorder(BST *root){
            BST *temp = root ;
            stack<BST*> st ;

            while(temp != NULL || !st.empty()){
                if(temp != NULL){
                    st.push(temp) ;
                    temp = temp->left ;
                }
                else{
                    temp = st.top() ;
                    st.pop() ;
                    cout << temp->data << "  " ;
                    temp = temp->right ;
                }
            }
        }
        BST *deleteNode(BST *root,int key) {
            if(root == NULL){
                cout << "can not delete empty BST" << endl ;
                return root ;
            }

            if(key < root->data){
                root->left = deleteNode(root->left , key) ;
            }
            else if(key > root->data){
                root->right = deleteNode(root->right , key) ;
            }
            else{
                if(root->left == NULL && root->right == NULL){
                    return NULL ;
                }
                else if(root->left == NULL){
                    BST *temp = root->right ;
                    free(root) ;
                    return temp ;
                }
                else if(root->right == NULL){
                    BST *temp = root->left ;
                    free(root) ;
                    return temp ;
                }

                BST *temp = minValueNode(root->right) ;
                root->data = temp->data ;
                root->right = deleteNode(root->right,temp->data) ;
            }
        }
        BST *minValueNode(BST *root){
            while(root && root->left != NULL)
                root = root->left ;
            return root ;    
        }
        bool search_in_bst(BST *root , int key){
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
};



int main() {
    BST *root = NULL , b ;
    root = b.insert(root,50) ;
    b.insert(root,30) ;
    b.insert(root,20) ;
    b.insert(root,100) ;
    b.insert(root,70) ;
    b.insert(root,60) ;
    b.insert(root,80) ;
    b.insert(root,67) ;

    root = b.deleteNode(root,70) ;
    root = b.deleteNode(root,100) ;
    root = b.deleteNode(root,30) ;
    root = b.deleteNode(root,67) ;

    b.inorder(root) ;

    int key ;
    cout << endl ;
    cout << "enter which element you want to find:" ;
    cin >> key ;
    bool idx = b.search_in_bst(root,key) ;
    
    if(idx)
        cout << "element is found in BST" ;
    else
        cout << "elment is not found" ;    


    
}