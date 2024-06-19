#include <bits/stdc++.h>

using namespace std ;

int perform_operation(int o1,int o2 , char operator){
    if(operator == '+')
        return o1+o2 ;
    else if(operator == '-') 
        return o1-o2 ;
    else if(operator == '*')
        return o1*o2 ;
    else 
        return o1/o2 ;            
}


int postfix_expression_evaluation(string s){
    stack<char> st; 
    int value = 0 , i = 0 ;

    char next = s[i] ;
    i++ ;

    while(next != '\0'){
        if(isdigit(next)){
            st.push(next) ;
        }
        else{
            char operand1 = st.top() ;
            st.pop() ;
            char operand2 = st.top() ;
            st.pop() ;
            value = perform_operation(operand1-'0',operand2-'0',next) ;
            st.push(value) ;
        }
        next = s[i] ;
        i++ ;
    }
    int ans = st.top() ;
    st.pop() ;
    return ans ;
}



int main() {
   string s ;
   cout << "enter postfix expression : " ;
   cin >> s ;

   cout << postfix_expression_evaluation(s) << endl ;
   
    return 0 ;
}