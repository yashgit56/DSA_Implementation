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

    //logic is completely same as next smaller element just we have to traverse the array
    // in reverse order

    int prev_smaller[n] ;

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(st.empty()){
            st.push(i) ;
        }
        else{
            while(!st.empty() && arr[i] < arr[st.top()]){
                int index = st.top() ;
                st.pop() ;
                prev_smaller[index] = arr[i] ;
            }
            st.push(i) ;
        }
    }
    while(!st.empty()){
        prev_smaller[st.top()] = -1 ;
        st.pop() ;
    }
    print_array(prev_smaller,n);



}