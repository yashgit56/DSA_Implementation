
 
#include <bits/stdc++.h>
using namespace std ;

void maxHeapify(int arr[] , int n , int i){
    // first consider root node as largest and find left child is 2*i and right child is 2*i + 1
    int largest = i , left = 2*i + 1  , right = 2*i + 2 ;

    // check largest element and left and right child which is highest swap largest with it
    if(left < n && arr[left] > arr[largest])
        largest = left ;
    if(right < n && arr[right] > arr[largest])
        largest = right ;
    if(largest != i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest) ;
    }        
}
void heapSort(int arr[] , int n ){
    // building max heap using maxHeapify Method
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        maxHeapify(arr,n,i);
    }
    // now sorting using heapsort
    for(int i = n-1 ; i> 0 ; i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0) ;
    }
}

 
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int n ;
    cout << "enter number of elements: " ;
    cin >> n ;

    int arr[n] ;
    cout << "now enter elements one by one:"  << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    
    heapSort(arr, n);
    printf("Sorted array is\n");
    printArray(arr, n);
}