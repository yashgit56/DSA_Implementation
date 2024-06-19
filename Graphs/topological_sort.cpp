#include <bits/stdc++.h>
using namespace std ;

vector<int> visited ;
vector<vector<int>> graph ;
stack<int> st ;

void topological_sort(int src){
    visited[src] = 1 ;

    for(auto i : graph[src]){
        if(!visited[i]){
            topological_sort(i) ;
        }
    }
    st.push(src) ;
}



using namespace std ;
int main() {
    int n ;
    cout << "enter number of nodes:" ;
    cin >> n ; 

    visited.assign(n+1,0) ;
    graph.resize(n+1) ;

    for(int i = 0 ; i < n+2 ; i++){
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
    vector<int> topological_list ;
    while(!st.empty()){
        topological_list.push_back(st.top()) ;
        st.pop() ;
    }
    for(auto i : topological_list){
        cout << i << " " ;
    }
    cout << endl ;



}