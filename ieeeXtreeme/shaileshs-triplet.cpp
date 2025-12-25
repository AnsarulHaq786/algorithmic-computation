#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    cin >> test;
    for (int t=0; t<test; t++) {
        long long N;
        cin>>N;

        if(N%2!=0) {
            cout<<"-1"<<endl;
            continue;
        }
        long long a, b;
        bool found=false;
        for (a=1; a<=2*N && !found; a++) {
            for (b=1; b<=2*N; b++) {
                if(a==b) continue;
                long long c=2*N-a-b;
                if(c<=0 || c==a || c==b) continue;

                if((a^b^c)==N) {
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    found=true;
                    break;
                }
            }
        }
        if(!found) cout<<"-1"<<endl;
    }

    return 0;
}
