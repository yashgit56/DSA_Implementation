#include<bits/stdc++.h>
using namespace std ;

int partition(int *arr , int low , int high){
    int pivot = arr[low] ;
    int start = low  , end = high ;

    while(start < end){
        while(arr[start] <= pivot){
            start++ ;
        }
        while(arr[end] > pivot){
            end-- ;
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[low] , arr[end]) ;
    return end ;
}

void Quick_sort(int arr[] , int low , int high){
    if(low < high){
        int partitionIndex = partition(arr,low,high) ;
        Quick_sort(arr , low , partitionIndex - 1) ;
        Quick_sort(arr, partitionIndex + 1 ,high) ;
    }
}
after 1st step
// 3 4 2 1 2
// 3 2 2 1 4
// 1 2 2 3 4


int main() {
    int n ;
    cout << "enter number of elements:" ;
    cin >> n ;

    int arr[n] ;
    cout << "now enter elements one by one:" ;
    cout << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    Quick_sort(arr,0,n-1) ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}