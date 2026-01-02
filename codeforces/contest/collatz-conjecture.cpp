#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    for(int t=0; t<test; t++) {
        int k, x;
        cin>>k;
        cin>>x;
        cin.ignore();
        for(int i=0; i<k; ++i) {
           if((x-1)/3%2!=0) x=(x-1)/3;
            else x*=2;
        }
        cout<<x<<endl;
    }
    
    return 0;
}