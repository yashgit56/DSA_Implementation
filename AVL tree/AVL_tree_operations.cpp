#include <bits/stdc++.h>

using namespace std ;

class AVL {
        int data ;
        AVL *left , *right ;
        int height ;
    public:
        AVL(int key = 0 ){
            data = key ;
            left = NULL ;
            right = NULL ;
            height = 0 ;
        }
        int getMaxHeight(AVL * node){
            if(node == NULL)
                return 0 ;
            return node->height ;    
        }
        int getBalanceFactor(AVL *node){
            if(node == NULL)
                return 0 ;
            return getMaxHeight(node->left) - getMaxHeight(node->right) ;    
        }
        AVL * RR_Rotation(AVL * y){
            AVL * x = y->left ;
            AVL * c2 = x->right ;

            y->left = c2 ;
            x->right = y ;  

            y->height = max(getMaxHeight(y->right),getMaxHeight(y->left));
            x->height = max(getMaxHeight(x->right),getMaxHeight(x->left));

            return x ;
        }
        AVL * LL_Rotation(AVL * x){
            AVL *y = x->right ;
            AVL *c2 = y->left ;

            x->right = c2 ;
            y->left = x ;

            y->height = max(getMaxHeight(y->right),getMaxHeight(y->left));
            x->height = max(getMaxHeight(x->right),getMaxHeight(x->left));

            return y ;
        }
        AVL * insertion (AVL *root , int key){
            if(root == NULL)
                return new AVL(key) ;

            if(key < root->data)
                root->left = insertion(root->left , key) ;
            else
                root->right = insertion(root->right , key) ;

            root->height = max(getMaxHeight(root->left),getMaxHeight(root->right)) ; 
            int balanceFactor = getBalanceFactor(root) ;      

            // right-right rotation
            if(balanceFactor < -1 && key > root->right->data)
                RR_Rotation(root) ;

            // left-left rotation    
            if(balanceFactor > 1 && key < root->left->data)
                LL_Rotation(root) ;

            // right-left rotation
            if(balanceFactor < -1 && key < root->right->data){
                root->right = RR_Rotation(root->right) ;
                LL_Rotation(root) ;
            }

            // left-right rotation
            if(balanceFactor > 1 && key > root->left->data){
                root->left = LL_Rotation(root->left) ;
                RR_Rotation(root) ;
            }
            return root ;    
        }
        void inorder(AVL *root){
            AVL *temp = root ;
            stack<AVL*> st ;

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

};

int main() {
     AVL *root = NULL , b ;
    root = b.insertion(root,63) ;
    b.insertion(root,9) ;
    b.insertion(root,19) ;
    b.insertion(root,27) ;
    b.insertion(root,18) ;
    b.insertion(root,108) ;
    b.insertion(root,99) ;
    b.insertion(root,81) ;

    b.inorder(root) ; 

    
}