#include<iostream>
using namespace std ;

// time complexivity is O(n^2) in best case as well as in worst because every time 
// we have to do n^2 comparisions
// selection sort is unstable sort and inplace sort 
//  Stable Sort is one which preserves the original order of input set, where the 
// comparison algorithm does not distinguish between two or more items. 
// in place sort means there is extra space required or not for sorting method 

void selection_sort(int arr[] , int n){
    for(int i = 0 ; i < n - 1; i++){
        int min_index = i ;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[min_index] > arr[j])
                min_index = j ;
        }
        int temp = arr[min_index] ;
        arr[min_index] = arr[i] ;
        arr[i] = temp ;
    }
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
    selection_sort(arr,n) ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}