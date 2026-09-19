#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, u, v;
	cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<bool> b(n, false);
    vector<bool> seen(n, false);
    unordered_map<int, int> counts;
    int flags = 0;
    auto dfs = [&](this auto self, int i) -> void {
        bool toUpdate = false;
        if(counts[a[i]] == 1){
            toUpdate = true;
        }
        counts[a[i]]++;
        if(toUpdate) {
            flags++;
        }
        b[i] = (flags > 0);
        seen[i] = true;
        for(int& x : adj[i]){
            if(!seen[x]) self(x);
        }
        counts[a[i]]--;
        if(toUpdate) flags--;
    };
    dfs(0);
    for(int i = 0; i < n; i++){
        cout << (b[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}