#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int test=0; test<t; test++) {
        int n, m;
        string a, b, c;
        cin>>n;
        cin>>a;
        cin>>m;
        cin>>b;
        cin>>c;
        for(int i=0; i<m; i++) {
            if(c[i]=='D') a.push_back(b[i]); 
            else a=b[i]+a;
        }
        cout<<a<< endl;
    }
    return 0;
}