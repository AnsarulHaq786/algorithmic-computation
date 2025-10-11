/*
263A_beautiful-matrix
 
simplified problem statement:
given 5*5 matrix, has 24 zeroes and a single one, count no of steps required to move 1 to the center of the matrix i.e at 3*3 spot of the matrix,
conditions
- 1 can't move diagonaly,
- single step counts as one
 
Examples
Input
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Output
3
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int c, flag=0;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin>>c;
            if(c) cout<<abs(2-i)+abs(2-j);
        }
    }
    return 0;
}