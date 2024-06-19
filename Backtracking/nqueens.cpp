#include <bits/stdc++.h>

using namespace std ;
int n ;

bool place(int k , int i,int ans[]){
    for(int j = 1 ; j <= k-1 ; j++){
        if(ans[j] == i || abs(j-k) == abs(ans[j] - i))
            return false ;
    }
    return true ;
}

void N_queens(int k , int n, int ans[]){
    for(int i = 1 ; i <= n ; i++){
        cout << "place(" << k << " , " << i << ")" << endl ;
        if(place(k,i,ans)){
            ans[k-1] = i ;
            if(k  == n-1){
                for(int i = 0 ; i < n ;i++){
                    cout << ans[i] << " " ;
                }
                cout << endl ;
            }
            else{
                N_queens(k,n,ans) ;
            }
        }
    }
}
int main() {
    int n ;
    cout << "Enter number of row and column: " << " " ;
    cin >> n ;

    int ans[n] ;
    for(int i = 0 ; i < n ; i++){
        ans[i] = 0 ;
    }
    int k = 1 ;
    N_queens(k,n,ans) ;

    return 0 ;
}