/* Simulation of KS Test
- find random numbers
- scale them by dividing random numbers using modulo value(m)
To perform K-S test
- rank the data from smallest to largest
- number are computed from the empirical distribution Sn(X) i.e. i/N
- compute the deviations
    - D^+=max(i/N-Ri);
    - D^-=max(Ri-(i-1)/N);
    - D=max(D^+, D^-);
    - D$a$>D ;then accept
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 37, c = 41, m = 1000, x, i, n = 10;
    printf("Enter a seed value: ");
    if (scanf("%d", &x) != 1) return 1;

    /* generate pseudo-random integers using LCG, store as doubles */
    double r[10];
    x = x % m;
    if (x < 0) x += m;
    r[0] = (double)x;
    for (i = 0; i < n - 1; i++) {
        int next = (a * (int)r[i] + c) % m;
        if (next < 0) next += m;
        r[i + 1] = (double)next;
    }

    printf("Generated integers:\n");
    for (i = 0; i < n; i++) printf("%d ", (int)r[i]);
    printf("\n");

    /* scale to [0,1) */
    for (i = 0; i < n; i++) r[i] /= (double)m;

    printf("Scaled values [0,1):\n");
    for (i = 0; i < n; i++) printf("%.6f ", r[i]);
    printf("\n");

    /* sort ascending (selection sort) */
    int j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (r[j] < r[min]) min = j;
        }
        if (min != i) {
            double tmp = r[i];
            r[i] = r[min];
            r[min] = tmp;
        }
    }

    printf("Sorted values:\n");
    for (i = 0; i < n; i++) printf("%.6f ", r[i]);
    printf("\n");

    /* compute empirical deviations for Kolmogorov-Smirnov */
    double N = (double)n;
    double Dplus = 0.0, Dminus = 0.0;
    for (i = 1; i <= n; i++) {
        double Ri = r[i - 1];
        double val_plus = (i / N) - Ri;
        if (val_plus > Dplus) Dplus = val_plus;
        double val_minus = Ri - ((i - 1) / N);
        if (val_minus > Dminus) Dminus = val_minus;
    }
    double D = (Dplus > Dminus) ? Dplus : Dminus;

    printf("D+ = %.6f\n", Dplus);
    printf("D- = %.6f\n", Dminus);
    printf("D  = %.6f\n", D);

    return 0;
}