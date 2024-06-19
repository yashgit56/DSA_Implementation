#include<iostream>
#include<stack>

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

void postorder_iterative(Node *root){
    
    stack<Node*> st ;
    while(root != NULL || !st.empty()){
        if(root != NULL){
            st.push(root) ;
            root = root->left ;
        }
        else{
            Node * temp = st.top()->right ;
            if(temp == NULL){
                temp = st.top() ;
                st.pop() ;
                cout << temp->data << " " ;
                while(!st.empty() && st.top()->right == temp){
                    temp = st.top() ;
                    st.pop() ;
                    cout << temp->data << " " ;
                }
            }
            else
                root = temp ;
        }
    }

}

int main(){
    // creating all nodes of binary tree 
    Node * p1 = create_node(1) ;
    Node * p2 = create_node(7) ;
    Node * p3 = create_node(9) ;
    Node * p4 = create_node(2) ;
    Node * p5= create_node(6) ;
    Node * p6 = create_node(9) ;
    Node * p7= create_node(5) ;
    Node * p8= create_node(11) ;
    Node * p9 = create_node(5) ;

    // make connections between all binary tree nodes
    p1->left = p2 ;
    p1->right = p3 ;

    p2->left = p4 ;
    p2->right = p5 ;

    p5->left = p7 ;
    p5->right = p8 ;

    p3->right = p6 ;
    p6->left = p9 ;

    postorder_iterative(p1) ;


    return 0 ;
}