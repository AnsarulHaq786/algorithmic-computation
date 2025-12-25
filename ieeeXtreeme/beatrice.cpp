#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE1 = 131;
const int BASE2 = 13131;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> children(N+1);
    vector<bool> visited(N+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                children[u].push_back(v);
                q.push(v);
            }
        }
    }
    
    vector<int> order;
    queue<int> q2;
    q2.push(1);
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        order.push_back(u);
        for (int v : children[u]) {
            q2.push(v);
        }
    }
    reverse(order.begin(), order.end());
    
    vector<long long> h1(N+1), h2(N+1);
    for (int u : order) {
        vector<long long> list1, list2;
        for (int v : children[u]) {
            list1.push_back(h1[v]);
            list2.push_back(h2[v]);
        }
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        long long res1 = 1;
        for (long long x : list1) {
            res1 = (res1 * BASE1 + x) % MOD1;
        }
        long long res2 = 1;
        for (long long x : list2) {
            res2 = (res2 * BASE2 + x) % MOD2;
        }
        h1[u] = res1;
        h2[u] = res2;
    }
    
    vector<bool> unique(N+1, false);
    unique[1] = true;
    queue<int> q3;
    q3.push(1);
    int ans = 0;
    while (!q3.empty()) {
        int u = q3.front();
        q3.pop();
        ans++;
        map<pair<long long, long long>, vector<int>> groups;
        for (int v : children[u]) {
            groups[{h1[v], h2[v]}].push_back(v);
        }
        for (auto &it : groups) {
            if (it.second.size() == 1) {
                unique[it.second[0]] = true;
                q3.push(it.second[0]);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}