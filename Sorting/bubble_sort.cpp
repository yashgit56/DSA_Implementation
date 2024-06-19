#include<iostream>
using namespace std ;
// time complexivity is O(n^2) in best case as well as in worst because every time 
// we have to do n^2 comparisions
// bubble sort is unstable sort and inplace sort 
//  Stable Sort is one which preserves the original order of input set, where the 
// comparison algorithm does not distinguish between two or more items. 
// in place sort means there is extra space required or not for sorting method 

void bubble_sort(int arr[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ; 
            }
        }
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
    bubble_sort(arr,n) ;
    cout << "sorted elements are following: " << endl ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}