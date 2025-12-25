#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    
    vector<vector<int>> original(N, vector<int>(M, -1));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') {
                original[i][j] = grid[i][j] - '0';
            }
        }
    }
    
    // Group cells that must be equal using Union-Find
    map<pair<int,int>, pair<int,int>> parent;
    
    function<pair<int,int>(pair<int,int>)> find = [&](pair<int,int> x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };
    
    auto unite = [&](pair<int,int> a, pair<int,int> b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
        }
    };
    
    // Find row palindrome constraints - only for contiguous sequences
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < M) {
            if (original[i][j] == -1) { j++; continue; }
            
            vector<int> cols;
            while (j < M && original[i][j] != -1) {
                cols.push_back(j);
                j++;
            }
            
            // Only process if we have more than 1 cell
            if (cols.size() > 1) {
                int len = cols.size();
                for (int l = 0, r = len - 1; l < r; l++, r--) {
                    unite({i, cols[l]}, {i, cols[r]});
                }
            }
        }
    }
    
    // Find column palindrome constraints - only for contiguous sequences
    for (int j = 0; j < M; j++) {
        int i = 0;
        while (i < N) {
            if (original[i][j] == -1) { i++; continue; }
            
            vector<int> rows;
            while (i < N && original[i][j] != -1) {
                rows.push_back(i);
                i++;
            }
            
            // Only process if we have more than 1 cell
            if (rows.size() > 1) {
                int len = rows.size();
                for (int l = 0, r = len - 1; l < r; l++, r--) {
                    unite({rows[l], j}, {rows[r], j});
                }
            }
        }
    }
    
    // Group cells by their equivalence class
    map<pair<int,int>, vector<pair<int,int>>> groups;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (original[i][j] != -1) {
                auto root = find({i, j});
                groups[root].push_back({i, j});
            }
        }
    }
    
    // For each group, find the value that minimizes total cost
    vector<vector<int>> result(N, vector<int>(M, -1));
    
    for (auto& [root, cells] : groups) {
        // Find min and max original values in this group
        int min_val = 9, max_val = 0;
        for (auto [i, j] : cells) {
            min_val = min(min_val, original[i][j]);
            max_val = max(max_val, original[i][j]);
        }
        
        // Try all values in range and pick the one with minimum cost
        int best_val = min_val;
        long long min_cost = LLONG_MAX;
        
        for (int v = min_val; v <= max_val; v++) {
            long long cost = 0;
            for (auto [i, j] : cells) {
                cost += abs(original[i][j] - v);
            }
            if (cost < min_cost || (cost == min_cost && v < best_val)) {
                min_cost = cost;
                best_val = v;
            }
        }
        
        // Assign this value to all cells in the group
        for (auto [i, j] : cells) {
            result[i][j] = best_val;
        }
    }
    
    // Print final matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (result[i][j] == -1) cout << '.';
            else cout << result[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}