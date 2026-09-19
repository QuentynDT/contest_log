#include <bits/stdc++.h>

using namespace std;
void solve(){
    constexpr int kMod = 1'000'000'007;
    int n;
    cin >> n;
    vector<pair<int,int>> tree(n + 1);
    vector<int> descent(n + 1, 0);
    vector<int> parent(n + 1, -1);
    vector<int> ans(n);
    parent[1] = 0;
    tree[0].first = 1;
    for(int i = 1; i <= n; i++){
        cin >> tree[i].first >> tree[i].second;
        if(tree[i].first != 0){
            parent[tree[i].first] = i;
            parent[tree[i].second] = i;
        }
    }
    auto dfs = [&](this auto self, int i) -> int {
        if(tree[i].first == 0) return 0;
        int x = (2 + self(tree[i].first)) % kMod, y = (2 + self(tree[i].second)) % kMod;
        descent[i] = (x + y) % kMod;
        return descent[i];
    };
    auto dfstd = [&](this auto self, int i, int sum) -> void {
        if (i == 0) return;
        int curr = (descent[i] + sum + 1) % kMod;
        ans[i-1] = curr;
        self(tree[i].first, curr);
        self(tree[i].second, curr);
    };
    dfs(1);
    dfstd(1, 0);
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
	cin >> t;
	while(t--){
        solve();
    }
	return 0;
}