/*
    Middle square method of random number generation
    - input: seed(4-digit)
    - square the seed
    - goto select middle 4 numbers, (:modulus to 10000)
    - output the number
*/

#include <iostream>
using namespace std;

int main(){
    int seed, n;
    cout<<"Enter a seed: ";
    cin>>seed;
    cout<<"Enter number of random numbers: ";
    cin>>n;
    cout<<"\nGenerated Random Numbers:\n";
    for(int i=0; i<n; ++i){
        int square=seed*seed;
        int middle=(square%1000000)/100;
        cout<<middle<<endl;
        seed=middle;
    }
    return 0;
}
