/* 282A_bit++

simplified problem statement:
given program in bit++, where there is just two operations,
++x which increases value of x by 1 and --x which decreases value of x by 1.
operations could follow up after the variable,
given number of operations to be done, and the operation itself, find out the output of the sequence,
value of x=0, initially

Input
The first line contains a single integer n (1 ≤ n ≤ 150) — the number of statements in the programme.
Next n lines contain a statement each. Each statement contains exactly one operation (++ or --) and exactly one variable x (denoted as letter «X»). Thus, there are no empty statements. The operation and the variable can be written in any order.

Output
Print a single integer — the final value of x.

Examples
Input
1
++X

Output
1
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n; // input number of operations
    vector<string> s(n); // initialize array of string
    int res=0; // initialize output value
    for(int i=0; i<n; i++) { // storing
        cin>>s[i];
    }
    for(int i=0; i<n; i++) {
        if(s[i][0]=='+' || s[i].back()=='+') res++; // check for first and last character and execute operation based on that
        else if(s[i][0]=='-' || s[i].back()=='-') res--;
    }
    cout<<res; // output final result
    return 0;
}