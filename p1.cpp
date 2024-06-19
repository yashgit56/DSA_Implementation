#include <iostream>

using namespace std ;

void solve() {
    int n = 7 ;
    int arr[n] = {2,6,1,2,4,5,7} ;

    for(int i = 0 ; i < n ; i++){
        if( n % (i+1) == 0){
            max_val = n*arr[i] ;
        }
        else{
            max_val = arr[n/(i+1)] + (n % (i+1)) ;
        }
    }
    

    
    
}

int main() {
    int t ;
    cin >> t ;

    while(t--){
        solve() ;
    }


    return 0 ;
}