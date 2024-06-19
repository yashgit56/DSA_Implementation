#include <bits/stdc++.h>
using namespace std ;
int n ;
vector<int> visited , topological_sort , indegree ;
vector<vector<int>> graph ;
stack<int> st ;

vector<int>  topological_sort(int src){
    queue<int> q ;
    for(int i = 0 ; i < n; i++){
        for(auto i : graph[i])
            indegree[i]++ ;
    }
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0)
            q.push(i) ;
    }
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topological_sort.push_back(node) ;

        for(auto i : graph[node]){
            indegree[i]-- ;
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

    }
    return topological_sort ;
}



using namespace std ;
int main() {
    cout << "enter number of nodes:" ;
    cin >> n ; 

    visited.assign(n,0) ;
    graph.resize(n+1) ;
    indegree.assign(n,0) ;

    for(int i = 0 ; i < n ; i++){
        int u ,v ;
        cin >> u >> v ;

        graph[u].push_back(v) ;
        // graph[v].push_back(u) ;
    }
    bool possible = false ;
    for(int i = 1 ;i <= n ; i++){
        if(!visited[i]){
            topological_sort(i) ;
        }
    }

}