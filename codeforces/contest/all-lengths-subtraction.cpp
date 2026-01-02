#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    for(int t=0; t<test; t++) {
        int n, flag=1;
        cin>>n;
        int arr[n];
        for(int k=0; k<n; k++) {
            cin>>arr[k];
        }
        for(int i=n; i>0; i--) {
            int k;
            for(int j=0; j<n; j++) {
                if(arr[j]==i) {
                    arr[j]--;
                    k=j;
                }
            }
            if((arr[k-1])!=arr[k] && (arr[k+1])!=arr[k]) {
                flag=0;
                break;
            }
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}