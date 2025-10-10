/*
50A_domino-piling

simplified problem statement:
given a m*n rectangular board, how any of 2*1 board(domino) fit into it,
conditions:
- no two dominos overlap
- dominos not allowed to be outside of the board

Input
In a single line you are given two integers M and N — board sizes in squares (1 ≤ M ≤ N ≤ 16).
Output
Output one number — the maximal number of dominoes, which can be placed.

Examples
Input
2 4
Output
4
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin>>m>>n;
    cout<<(m*n)/2;
    return 0;
}