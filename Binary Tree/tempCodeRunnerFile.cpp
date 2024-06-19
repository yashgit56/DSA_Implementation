Node *p = root ;

    while(true){
        if(p != NULL){
            cout << p->data << " " ;
            st.push(p) ;
            p = p->left ;
        }
        else{
            if(st.empty())
                break ;
            p = st.top() ;
            st.pop() ; 
            p = p->right ;     
        }
    }