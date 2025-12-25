#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
        int k = n / 6;
        
        vector<vector<int>> groups(k);
        vector<set<int>> states(6);
        
        for (int i = 0; i < k; i++) {
            states[0].insert(i);
        }
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int group_id = -1;
            int from_state = -1;
            
            if (c == '0') {
                if (!states[3].empty()) {
                    group_id = *states[3].begin();
                    from_state = 3;
                }
            } else if (c == '1') {
                if (!states[1].empty()) {
                    group_id = *states[1].begin();
                    from_state = 1;
                } else if (!states[0].empty()) {
                    group_id = *states[0].begin();
                    from_state = 0;
                } else if (!states[4].empty()) {
                    group_id = *states[4].begin();
                    from_state = 4;
                }
            } else if (c == '2') {
                if (!states[2].empty()) {
                    group_id = *states[2].begin();
                    from_state = 2;
                } else if (!states[5].empty()) {
                    group_id = *states[5].begin();
                    from_state = 5;
                }
            }
            
            if (group_id == -1) {
                valid = false;
                break;
            }
            
            groups[group_id].push_back(i + 1);
            states[from_state].erase(group_id);
            if (from_state < 5) {
                states[from_state + 1].insert(group_id);
            }
        }
        
        if (!valid) {
            cout << -1 << "\n";
        } else {
            for (const auto& group : groups) {
                for (size_t j = 0; j < group.size(); j++) {
                    if (j > 0) cout << " ";
                    cout << group[j];
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}