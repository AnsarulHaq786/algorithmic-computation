#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1000000007;

int addmod(int a, int b) { a += b; if(a >= MOD) a -= MOD; return a; }
int submod(int a, int b) { a -= b; if(a < 0) a += MOD; return a; }
int mulmod(int a, int b) { return (int64)a * b % MOD; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M;
    cin >> M;
    
    vector<int> partitions(M + 1, 0);
    partitions[0] = 1;
    
    // Precompute partitions (increasing sequences)
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j++) {
            partitions[j] = addmod(partitions[j], partitions[j - i]);
        }
    }
    
    vector<int> ans(M + 1, 0);
    
    // For bitonic sequences with peak p and total sum N:
    // We need sum of partitions[a-p] * partitions[b-p] for a + b = N + p
    // where partitions[k] = number of partitions of k with all parts <= p
    
    // We can optimize by iterating over p and using prefix sums
    for (int p = 1; p <= M; p++) {
        vector<int> dp_part(M + 1, 0);
        dp_part[0] = 1;
        
        // Compute partitions with maximum part size p
        for (int i = 1; i <= p; i++) {
            for (int j = i; j <= M; j++) {
                dp_part[j] = addmod(dp_part[j], dp_part[j - i]);
            }
        }
        
        // For each possible total sum N
        for (int N = p; N <= M; N++) {
            // We need a + b = N + p, with a >= p, b >= p
            // So a ranges from p to N
            for (int a = p; a <= N; a++) {
                int b = N + p - a;
                if (b < p) continue;
                
                int left = (a == p) ? 1 : dp_part[a - p];
                int right = (b == p) ? 1 : dp_part[b - p];
                
                ans[N] = addmod(ans[N], mulmod(left, right));
            }
        }
    }
    
    // Print results
    for (int i = 1; i <= M; i++) {
        cout << ans[i] << (i == M ? '\n' : ' ');
    }
    
    return 0;
}