#include<bits/stdc++.h>
using namespace std;

int checkFirstHalf(int a, int b) {
    if(a==b) return 1;
    if(a>b && a/(b+1)<3) return 1;
    else if(a<b && b/(a+1)<3) return 1;
    else return 0;
}

int checkSecondHalf(int c, int d) {
    if(c==d) return 1;
    if(c>d && c/(d+1)<3) return 1;
    else if(c<d && d/(c+1)<3) return 1;
    else return 0;
}

int main() {
    int test;
    cin>>test;
    vector<bool> ans;
    for(int t=1; t<=test; t++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int flag1=checkFirstHalf(a, b);
        int flag2=checkSecondHalf(c, d);
        if(flag1 && flag2) ans.push_back(1);
        else ans.push_back(0);
    }
    for(int i=0; i<test; i++) {
        if(ans[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}