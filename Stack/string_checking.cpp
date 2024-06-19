#include <bits/stdc++.h>

using namespace std ;

bool string_checking(string s){
    stack<int> st ;
    st.push('c');
    int i = 0 ;
    int next = s[i] ;
    i++ ;
    while(next != 'c'){
        if(next == ' ')
            return false ;
        else{
            st.push(next) ;
            next = s[i] ;
            i++ ;
        }    
    }
    while(st.top() != 'c'){
        next = s[i] ;
        i++ ;
        int temp = st.top() ;
        st.pop() ;
        if(temp != next )
            return false ;    
    }
    next = s[i] ;
    if(next == ' ')
        return true ;
    else 
        return false ;    
    
}



int main() {
    string s ;
    cout << "enter the string: " ;
    getline(cin >> ws,s) ;

    // string is type of WCWR type of or not 
    if(string_checking(s))
        cout  << "valid string" << endl ;
    else
        cout << "invalid string" << endl ;    
 
}