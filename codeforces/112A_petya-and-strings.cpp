/*
112A_petya-and-strings

simplified problem statement:
given the two strings of same size and diffent case characters,
if first string is less than second, print -1,
if first string is greter than second, pring 1,
if they are equal then print 0

Input
aaaa
aaaA

Output
0
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin>>str1>>str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if(str1<str2) cout<<"-1";
    else if(str1>str2) cout<<"1";
    else cout<<"0";
    return 0;
} 

