#include<bits/stdc++.h>
using namespace std ;

void merge(int arr[] , int low , int mid , int high){
    int i = low , j = mid + 1  , k = low , b[10000] ;
    
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            b[k++] = arr[i++] ;
        }
        else{
            b[k++] = arr[j++] ;
        }
    }
    while(i <= mid){
        b[k++] = arr[i++] ;
    }
    while(j <= high){
        b[k++] = arr[j++] ;
    }
    for(int j = 0 ; j <= high ; j++){
        arr[j] = b[j] ; 
    }
}

void Iterative_merge_sort(int arr[] , int n){
    int subsize , i ;

    for( subsize = 2 ; subsize <= n ; subsize *= 2)
    {
        for(i = 0 ; i + subsize - 1 < n ; i += subsize)
        {
            int low = i ;
            int high = i + subsize - 1 ;
            cout << low << " " << high << endl ;
            int mid = (low + high )/ 2 ;
            merge(arr,low,mid,high) ;
        }

    }
    if(subsize/2 < n){
        merge(arr,0,subsize/2-1,n) ;
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
    Iterative_merge_sort(arr,n) ;
    print_array(arr,n) ;
}