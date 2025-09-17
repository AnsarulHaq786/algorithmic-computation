/* 231A_team

simplified problem statement:
A, B, C are in a team of programming contest. They will solve problem if at least two of them are sure about the problem.
1 represents a player knows solution.
given the number of problems, calculate total number of solutions done by the team. 

Input
The first input line contains a single integer n (1 ≤ n ≤ 1000) — the number of problems in the contest. Then n lines contain three integers each, each integer is either 0 or 1. If the first number in the line equals 1, then Petya is sure about the problem's solution, otherwise he isn't sure. The second number shows Vasya's view on the solution, the third number shows Tonya's view. The numbers on the lines are separated by spaces.

Output
Print a single integer — the number of problems the friends will implement on the contest.

Input
3
1 1 0
1 1 1
1 0 0
Output
2
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int p, count=0;
    cin>>p; // input number of problems
    for(int i=0; i<p; i++) {
        int c=0;
        for(int j=0; j<3; j++) {
            int n;
            cin>>n;
            if(n) c++; // count number of players who can solve
        }
        if(c>=2) count++; // mark solvable if at least two can solve
    }
    cout<<count;
    return 0;
}

/*
alternative solution: build a 2d matrix of the input,
transform to single column matrix by checking c>=1 then 1
increasing count based on no. of 1 present in 1d matrix(array)
*/
