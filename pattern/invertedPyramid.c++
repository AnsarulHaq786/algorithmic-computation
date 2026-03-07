/*

*******
 *****
  ***
   *

*/

#include<iostream>
using namespace std;

int main() {
    int n=4;
    for(int i=1; i<=n; i++) {
        for(int k=i; k>0; k--) {
            cout<<" ";
        }
        for(int j=1; j<=2*(n-i+1)-1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}