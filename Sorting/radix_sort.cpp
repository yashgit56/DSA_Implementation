#include<bits/stdc++.h>
using namespace std ;
int getMax(int arr[] , int n){

    int maxValFromArray = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        if(maxValFromArray < arr[i]){
            maxValFromArray = arr[i] ;
        }
    }
    return maxValFromArray ;
}
void countSort(int arr[] , int n , int pos){
    int last_digits[10] = {0} ;
    int temp[n] ;

    for(int i = 0 ; i < n ; i++){
        ++last_digits[(arr[i]/pos)%10] ;
    }
    for(int i = 1 ; i < n ; i++ ){
        last_digits[i] += last_digits[i-1] ; 
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        temp[--last_digits[((arr[i]/pos) % 10)]]= arr[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        arr[i] = temp[i] ;
    }
}

void radix_sort(int arr[] , int n ){

    int maxVal = getMax(arr,n) ;

    for(int pos = 1 ; maxVal/pos > 0 ; pos *= 10 ){
        countSort(arr,n,pos) ;
    }
}

void print_array(int arr[] , int n){
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " " ;
    cout << endl ;    
}
  170   045   075   090    802    024    002    066
   0     5     5     0      2      4      2      6

   0     1     2     3      4      5      6      7
        802   002   024              066  
   0 1 2 3 4 5 6 7 8 9
   2 0 2 0 1 2 1 0 0 0
   2 2 4 4 5 7 8 8 8 8


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
    radix_sort(arr,n) ;
    print_array(arr,n) ;

    return 0 ;
}