#include <bits/stdc++.h>

using namespace std ;
// we have three towers named source , auxiliary and destination denoted by
// source as s , auxiliary as a and destination as d 
// to move all disks from source to destination 
// we perform this using some basic rules for tower of hanoi
// rules:
// 1. we can only move top of the disk to any tower 
// 2. can not put larger width disk to smaller width disk 

void tower_of_hanoi(int disk , char s , char a , char d){
        if(disk == 1)
            cout << "move disk " << disk << " from " << s << " to " << d << endl ;
        else{
            tower_of_hanoi(disk-1,s,d,a);
            cout << "move disk " << disk << " from " << s << " to " << d << endl ;
            tower_of_hanoi(disk-1,a,s,d) ;
        }     
}

int main() {
    int disks ;
    cout << "enter number of disk in source tower : " ;
    cin >> disks ; 

     tower_of_hanoi(disks , 's' , 'a' , 'd') ;
}