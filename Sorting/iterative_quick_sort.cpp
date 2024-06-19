#include<bits/stdc++.h>
using namespace std ;

int partition(int *arr , int low , int high){
    int pivot = arr[low] ;
    int start = low  , end = high ;

    while(start < end){
        while(arr[start] <= pivot){
            start++ ;
        }
        while(arr[end] > pivot){
            end-- ;
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[low] , arr[end]) ;
    return end ;
}

void Quick_sort(int arr[] , int low , int high){
    stack<pair<int,int>> st ;

    st.push({low,high});

    while(!st.empty()){
        auto temp = st.top() ;
        st.pop() ;

        int start = temp.first , end = temp.second ;
        int partitionIndex = partition(arr,start , end) ;

        st.push({start,partitionIndex-1});
        st.push({partitionIndex+1, end});
    }
}

int main() {
    int n ;
    cout << "enter number of elements:" ;
    cin >> n ;

    int arr[n] ;
    cout << "now enter elements one by one:" ;
    cout << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    Quick_sort(arr,0,n-1) ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}