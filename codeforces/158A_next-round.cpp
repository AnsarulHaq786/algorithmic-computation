/*
simplified problem statement:
given 'n' number of contestants in a contest and scores earned by them,
those contestents whose score is greater or equal to kth contestents score are eligible for next round

Input
8 5
10 9 8 7 7 7 5 5

Output
6

Input
4 2
0 0 0 0

Output
0

Note
In the first example the participant on the 5th place earned 7 points. As the participant on the 6th place also earned 7 points, there are 6 advancers.
In the second example nobody got a positive score.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    if(a[k-1]==0){
        int i=0, j=0;
        while(i<k-1) {
            if(a[i]!=0) j++;
            i++;
        }
        cout<<j<<endl;
    }
    else {
        while(a[k-1]==a[k]) {
            k++;
        }
        cout<<k<<endl;
    }
    
    return 0;
}