#include <bits/stdc++.h>

using namespace std ;
// we have three towers named source , auxiliary and destination denoted by
// source as s , auxiliary as a and destination as d 
// to move all disks from source to destination 
// we perform this using some basic rules for tower of hanoi
// rules:
// 1. we can only move top of the disk to any tower 
// 2. can not put larger width disk to smaller width disk 

int decimal_to_binary_using_stack(int n){
       stack<int> st ;

       int binary_value = 0 ; 
       while(n > 0){
            int temp = n % 2 ;
            st.push(temp) ;
            n /= 2 ;
       }
       while(!st.empty()){
            int temp = st.top() ;
            st.pop() ;
            binary_value += temp ;
            binary_value *= 10 ;
       }
       return binary_value ;

}

int main() {
    int n ;
    cout << "enter decimal number:" ;
    cin >> n ;

    cout << decimal_to_binary_using_stack(n) << endl ;
    
}