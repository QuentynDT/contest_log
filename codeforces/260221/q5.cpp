#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, id, orig_a;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), deg(n + 1, 0);
    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        adj[a[i]].push_back({b[i], i, a[i]});
        adj[b[i]].push_back({a[i], i, a[i]});
        deg[a[i]]++;
        deg[b[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ans;
    vector<bool> used_edge(n, false);
    
    for (int i = 1; i <= n; i++) {
        while (!adj[i].empty()) {
            if (used_edge[adj[i].back().id]) {
                adj[i].pop_back();
                continue;
            }

            // Hierholzer-style traversal to orient edges
            vector<int> stack = {i};
            while (!stack.empty()) {
                int u = stack.back();
                while (!adj[u].empty() && used_edge[adj[u].back().id]) {
                    adj[u].pop_back();
                }

                if (adj[u].empty()) {
                    stack.pop_back();
                } else {
                    Edge e = adj[u].back();
                    adj[u].pop_back();
                    used_edge[e.id] = true;
                    
                    // If the traversal moves from b[i] to a[i], it's a swap
                    if (e.orig_a != u) {
                        ans.push_back(e.id + 1);
                    }
                    stack.push_back(e.to);
                }
            }
        }
    }
    const int sz = ans.size();
    cout << sz << "\n";
    if(sz == n) return;
    for (int i = 0; i < sz; i++) {
        cout << ans[i] + 1 << (i == sz - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}