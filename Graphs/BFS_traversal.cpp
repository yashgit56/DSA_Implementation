#include <iostream>
#include <queue>

using namespace std ;
int main() {
    int i ;
    cout << "choose starting vertices:" ;
    cin >> i ;

    int visited[7] = {0,0,0,0,0,0,0} ;
    queue<int> q ;

    int arr[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    cout << i << " " ;
    visited[i] = 1 ;
    q.push(i) ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        for(int j = 0 ; j < 7 ; j++){
            if(arr[node][j] == 1 && visited[j] == 0){
                cout << j << " " ;
                visited[j] = 1 ;
                q.push(j) ;
             }
        }
    }
}