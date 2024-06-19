#include <iostream>
#include <cstdlib>

using namespace std ;
struct Stack {
    int size ;
    int top ;
    int *arr ;
};
int isEmpty(Stack *s){
    if(s->top == -1)
        return 1 ;
    else    
        return 0 ;    
}

int isFull(Stack *s){
    if(s->top == s->size - 1)
        return 1 ;
    else    
        return 0 ;    
}
void push(Stack *s , int value){
    if(isFull(s))
        cout << "Stack Overflow" << endl ;
    else{
        s->top++ ;
        s->arr[s->top] = value ;
        cout << "push "<< value << " in the  stack successfully" << endl ;
    }    
}
int pop(Stack *s){
    int element ;
    if(isEmpty(s))
        cout  << "Stack Underflow" << endl ;
    else{
        element = s->arr[s->top] ;
        s->top-- ;
    }
    return element ;    
}

int main() {
    Stack *s = new Stack()  ;
    cout << "enter the size of the stack :" ;
    cin >> s->size ;
    s->top = -1 ;
    s->arr = (int *)malloc(s->size * sizeof(int) ) ;


    push(s,20);
    push(s,30);
    push(s,40);
    cout << pop(s) << endl ;
    push(s,50);
    cout << pop(s) << endl ;
    cout << pop(s) << endl ;

    return 0 ;
}