#include <bits/stdc++.h>

using namespace std ;

int precedence(char sym){
    if(sym == '+' || sym == '-')
        return 1 ;
    else if(sym == '^')
        return 3 ;    
    else if(sym == '*' || sym == '/' )
        return 2 ;    
    else 
        return 0 ;            
}

void infix_to_postfix(string s){
    stack<char> st; // For stack operations, we are using
                    // C++ built in stack
    string result;

    for (int i = 0; i < s.length(); i++) {
        char next = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if ((next >= 'a' && next <= 'z') || (next >= 'A' && next <= 'Z')
            || (next >= '0' && next <= '9'))
            result += next; 
        else if (next == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (next == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty()
                   && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(next);
        }
    } while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;

    cout << result << endl ;
}



int main() {
   string s ;
   cout << "enter infix expression : " ;
   cin >> s ;

   infix_to_postfix(s) ;
   
    return 0 ;
}