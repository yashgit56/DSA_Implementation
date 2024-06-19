#include<iostream>
using namespace std ;

// time complexivity is O(n) in best case but in worst it is O(n^2) worst case for this method
// is where the given elements are sorted in reverse order  

// insertion sort is stable sort and inplace sort 
//  Stable Sort is one which preserves the original order of input set, where the 
// comparison algorithm does not distinguish between two or more items. 
// in place sort means there is extra space required or not for sorting method 

void insertion_sort(int arr[] , int n){
    for(int j = 1 ; j < n ; j++){
        int key = arr[j] ;
        int i = j - 1 ;

        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i] ;
            i-- ;
        }
        arr[i+1] = key ;
    }
}

int main() {
    int n ;
    cout << "enter number of elements:" ;
    cin >> n ;

    int arr[n] ;
    cout << "now enter elements one by one:" ;
    cout << endl ;
    for(int j = 0 ; j < n ; j++){
        cin >> arr[j] ;
    }
    insertion_sort(arr,n) ;
    for(int j = 0 ; j < n ; j++){
        cout << arr[j] << " " ;
    }
}