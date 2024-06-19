#include <iostream>

using namespace std ;
struct CircularQueue{
    int size ;
    int front ;
    int rear ;
    int *arr ;
};
 bool isFull ( CircularQueue *q){
    if((q->rear+1)%q->size == q->front)
        return true ;
    else
        return false ;    
}
bool isEmpty (CircularQueue *q){
    if(q->front == q->rear)
        return true ;
    else
        return false ;    
}
void qinsert(struct CircularQueue *q , int value){
    if(isFull(q)){
        cout <<  "CircularQueue is full " << endl ;
    }
    else{
        q->rear = (q->rear+1)%q->size ;
        q->arr[q->rear] = value ;
        cout << "enqueueing element:" << value << endl ;
    }
}
int qdelete(struct CircularQueue *q){
    int element = -1 ;
    if(isEmpty(q)){
        cout <<  "CircularQueue is empty" << endl ;
    }
    else{
        q->front = (q->front + 1)%q->size ;
        element = q->arr[q->front] ;
    }
    return element ;
}
int main() {
    struct CircularQueue q ;
    q.size = 3 ;
    q.front = q.rear = -1 ;

    q.arr = (int *)malloc(q.size * sizeof(int)) ;
    
    qinsert(&q,25) ;
    qinsert(&q,35) ;
    qinsert(&q,45) ;
    cout << "dequeueing element: " << qdelete(&q)  << endl ;
    cout << "dequeueing element: " << qdelete(&q)  << endl ;
    cout << "dequeueing element: " << qdelete(&q)  << endl ;
    qinsert(&q,55) ;
    qinsert(&q,65) ;
    qinsert(&q,75) ;
    qinsert(&q,85) ;
    
}