#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>

void solve(int n, int k) {
    vector<pii> indexed_vals;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        int mod_val = (val % k == 0) ? k : (val % k);

        // Store as (mod_val, position)
        indexed_vals.pb({mod_val, i + 1});
    }

    // Sort based on mod_val in descending order, break ties by original position
    sort(indexed_vals.begin(), indexed_vals.end(), [](pii a, pii b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });

    for (auto p : indexed_vals) {
        cout << p.second << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
        cout << "\n";
    }

    return 0;
}
