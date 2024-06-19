#include <iostream>
#include <stack>

using namespace std ;
int visited[7] = {0,0,0,0,0,0,0} ;

    int arr[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
void DFS(int i ){
    cout << i << " " ;
    visited[i] = 1 ;

    for(int j = 0 ; j < 7 ; j++){
        if(arr[i][j] == 1 && visited[j] == 0){
            DFS(j) ;
        }
    }
}
using namespace std ;
int main() {
    int i ;
    cout << "choose starting vertices:" ;
    cin >> i ;

    DFS(i) ;
    
    return 0 ;
}