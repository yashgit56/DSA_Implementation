#include <iostream>

using namespace std ;
struct Queue{
    int size ;
    int front ;
    int rear ;
    int *arr ;
};
 bool isFull(Queue *q){
    if(q->rear == q->size - 1)
        return true ;
    else
        return false ;    
}
bool isEmpty(Queue *q){
    if(q->front == q->rear)
        return true ;
    else
        return false ;    
}
void qinsert(struct Queue *q , int value){
    if(isFull(q)){
        cout << "Queue is full " << endl ;
    }
    else{
        q->rear = q->rear + 1 ;
        q->arr[q->rear] = value ;
        cout << "inserting " << value << " into queue successfully" << endl ;
    }
}
int qdelete(struct Queue *q){
    int element = -1 ;
    if(isEmpty(q)){
        cout << "Queue is empty" << endl ;
    }
    else{
        q->front = q->front + 1 ;
        element = q->arr[q->front] ;
    }
    return element ;
}
int main() {
    struct Queue q ;
    q.size = 3 ;
    q.front = q.rear = -1 ;

    q.arr = (int *)malloc(q.size * sizeof(int)) ;
    
    qinsert(&q,25) ;
    qinsert(&q,35) ;
    qinsert(&q,45) ;
    qinsert(&q,55) ;
    qinsert(&q,65) ;
    qinsert(&q,75) ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;
    cout << "deleting " << qdelete(&q) << " from queue successfully." << endl ;

    
}