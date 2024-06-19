#include<iostream>
using namespace std ;



void merge(int arr[] , int low , int mid , int high){
    int i = low , j = mid + 1  , k = low , b[10000] ;
    
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            b[k] = arr[i] ;
            i++ ; k++ ;
        }
        else{
            b[k] = arr[j] ;
            j++ ; k++ ;
        }
    }
    while(i <= mid){
        b[k] = arr[i] ;
        i++ ; k++ ;
    }
    while(j <= high){
        b[k] = arr[j] ;
        j++ ; k++ ;
    }
    for(int j = 0 ; j <= high ; j++){
        arr[j] = b[j] ; 
    }
}

void merge_sort(int arr[] , int low , int high){
    if(low < high){
        int mid = (low+high)/2 ;
        merge_sort(arr,low,mid) ;
        merge_sort(arr,mid+1,high) ;
        merge(arr,low,mid,high) ;
    }
}
void print_array(int arr[] , int n){
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " " ;
    cout << endl ;    
}
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
    merge_sort(arr,0,n-1) ;
    print_array(arr,n) ;
}