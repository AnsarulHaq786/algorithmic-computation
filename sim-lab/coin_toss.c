/*
coin toss
- input: n(number of tosses)
- initialize: heads=0, tails=0
- seed RNG
- loop n times
    - if toss=rand()%2==1, heads++
    - else tails++
- calculate probabilities
    - p(heads)=heads/n, P(tails)=tails/n
- output print value of heads, tails, P(heads), p(tails)
*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
    int n, i, head_count=0, tail_count=0, toss;
    printf("Enter number of toses:");
    scanf("%d", &n);
    srand(time(0));
    for(i=0; i<n; i++) {
        toss=rand()%2;
        printf("%d ", toss);
        if(toss%2==1) head_count++;
        else tail_count++;
    }
    float prob_head=(float)head_count/n, prob_tail=(float)tail_count/n;
    printf("\nheads: %d, probability of head: %.2f\n", head_count, prob_head);
    printf("tails: %d, probability of tail: %.2f", tail_count, prob_tail);
    return 0;
}