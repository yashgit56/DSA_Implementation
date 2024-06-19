#include <iostream>
#include <stack>

using namespace std ;
void takeInput(int arr[] , int n){
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
}
void print_array(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
int main() {
    // creating stack to store elements in Last in first out
    stack<int> st ;

    int n ;
    cout << "enter the size of array:" ;
    cin >> n ;

    // creating array to store elements 
    int arr[n] ;
    // now take input for array using function
    takeInput(arr , n) ;

    // now we are finding next smaller element in the array using stack 
    // // if there is no smaller element than current element then print -1

    // this approach is not good to solve the question because it will take O(n^2) time. 
    // int next_smaller[n] ;
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = i + 1 ; j < n ; j++){
    //         if(arr[i] > arr[j]){
    //             next_smaller[i] = arr[j] ;
    //             break ;
    //         }
    //     }
    // }
    // print_array(arr,n);
    // print_array(next_smaller,n);
    int next_smaller[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        if(st.empty()){
            st.push(i) ;
        }
        else{
            while(!st.empty() && arr[i] < arr[st.top()]){
                int index = st.top() ;
                st.pop() ;
                next_smaller[index] = arr[i] ;
            }
            st.push(i) ;
        }
    }
    while(!st.empty()){
        next_smaller[st.top()] = -1 ;
        st.pop() ;
    }
    print_array(next_smaller,n);



}