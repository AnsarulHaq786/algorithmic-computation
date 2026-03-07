/* Simulation of LCG using G
Linear Congruential Generator, to generate a sequence of 10 random numbers given 987 as a seed value and modulo m=1000. (take a=37 and c=41)
*/

#include<stdio.h>
int main() {
    int a=37, c=41, m=1000, x, i, n=10;
    printf("Enter a seed value: ");
    scanf("%d", &x);
    int r=x;
    for(i=0; i<n; i++) {
        printf("%d ", r);
        r=(a*r+c)%m;
    }
    return 0;
}