/*
   *
  ***
 *****
*******
*/

#include<iostream>
using namespace std;

int main() {

    for(int i=1; i<=4; i++) {
        for(int k=4-i; k>0; k--) {
            cout<<" ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}