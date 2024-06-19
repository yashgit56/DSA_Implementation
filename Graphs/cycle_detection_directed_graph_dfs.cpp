#include <bits/stdc++.h>
using namespace std ;

vector<int> visited ;
vector<vector<int>> graph ;

bool checkForCycle(int src , int parent = -1){
    visited[src] = 1 ;

    for(auto i : graph[src]){
        if(!visited[i]){
            if(checkForCycle(i , src))
                return true;
        }
        else if(i != parent)
            return true ;      
    }
    return false ;
}



using namespace std ;
int main() {
    int n ;
    cout << "enter number of nodes:" ;
    cin >> n ; 

    visited.assign(n+1,0) ;
    graph.resize(n+1) ;

    for(int i = 0 ; i < n ; i++){
        int u ,v ;
        cin >> u >> v ;

        graph[u].push_back(v) ;
        // graph[v].push_back(u) ;
    }
    bool possible = false ;
    for(int i = 1 ;i <= n ; i++){
        if(!visited[i]){
            if(checkForCycle(i))
                possible = true ;
        }
    }
    if(possible)
        cout <<"Cycle detection found" << endl ;
    else
        cout << "Cycle detection not found" << endl ;    



}