#include<iostream>
using namespace std;

int main() {
    int test, k;
    cin>>test;
    for(int t=0; t<test; t++) {
        int sum=0, count=0;
        cin>>k;
        for(int i=1; count!=k; i++) {
            int temp=i;
            while(temp!=0)
            {
                int ext=temp%10;
                sum+=ext;
                temp/=10;
                count++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}