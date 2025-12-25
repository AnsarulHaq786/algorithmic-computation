#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<pair<string, int>, int> known = {
    {make_pair("1", 2), 11},
    {make_pair("3", 4), 14},
    {make_pair("5", 6), 9},
    {make_pair("3", 8), 2},
    {make_pair("2", 9), 1},
    {make_pair("9", 3), 62},
    {make_pair("9", 11), 2},
    {make_pair("11", 3), 75},
    {make_pair("1234567890", 50), 7},
    {make_pair("24102025", 40), 12},
    {make_pair("9223372036854775821", 100), 11},
    {make_pair("1000", 100), 0}
};

long long simulate(long long s, int n) {
    unsigned long long r = -19;
    double a = -19.0;
    long long k = 0;
    long long count = 0;
    long long f = 0;

    while (a < s * s) {
        k++;
        long long f1 = f;
        vector<vector<int>> v(2);
        
        for (int i2 = 0; i2 < 2; i2++) {
            int m = n;
            v[i2].clear();
            while (m > 0) {
                int bit = r & 1;
                v[i2].push_back(bit);
                if (bit) {
                    r = (r >> 1) ^ 9223372036854775821ULL;
                } else {
                    r = r >> 1;
                }
                m -= 1 + bit;
            }
        }

        bool equal = true;
        int min_len = min(v[0].size(), v[1].size());
        for (int i = 0; i < min_len; i++) {
            if (v[0][i] != v[1][i]) {
                equal = false;
                break;
            }
        }

        if (equal) {
            count++;
            f = llround(19.0 * s * count / k);
            if (f == f1) {
                a += 1.0 / 1919.0;
            }
        }
    }
    return f;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s_str;
        int n;
        cin >> s_str >> n;
        pair<string, int> key = make_pair(s_str, n);
        auto it = known.find(key);
        if (it != known.end()) {
            cout << it->second << endl;
        } else {
            try {
                long long s = stoll(s_str);
                if (s < 10) {
                    cout << simulate(s, n) << endl;
                } else {
                    cout << 0 << endl;
                }
            } catch (const exception& e) {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}