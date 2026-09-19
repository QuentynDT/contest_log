#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> ask(long long k) {
    cout << "? " << k << endl;
    int q;
    cin >> q;
    if (q == -1) exit(0);
    if (q == 0) return {};
    vector<int> path(q);
    for (int i = 0; i < q; i++) {
        cin >> path[i];
    }
    return path;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> C(n + 1, 0);
    vector<long long> start_idx(n + 2, 0);
    long long total_paths = 0;
    long long low = 1, high = 1LL << 30;

    for (int i = 1; i <= n; i++) {
        long long ans = high + 1;
        long long l = low, r = high;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            vector<int> p = ask(mid);
            if (p.empty() || p[0] >= i) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        start_idx[i] = ans;
        low = ans;
    }
    long long l = start_idx[n], r = 1LL << 30, end_all = start_idx[n];
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (!ask(mid).empty()) {
            end_all = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    start_idx[n + 1] = end_all + 1;

    for (int i = 1; i <= n; i++) {
        C[i] = start_idx[i + 1] - start_idx[i];
    }

    vector<pair<int, int>> edges;
    for (int u = 1; u <= n; u++) {
        long long current_k = start_idx[u] + 1;
        while (current_k < start_idx[u + 1]) {
            vector<int> p = ask(current_k);
            int v = p[1];
            edges.push_back({u, v});
            current_k += C[v];
        }
    }
    cout << "! " << edges.size() << endl;
    for (auto &e : edges) {
        cout << e.first << " " << e.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}