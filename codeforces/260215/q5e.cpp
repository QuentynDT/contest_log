#include <bits/stdc++.h>

using namespace std;
void solve(){
    constexpr int kMod = 1'000'000'007;
    int n;
    cin >> n;
    vector<pair<int,int>> tree(n + 1);
    vector<pair<int,int>> descent(n + 1, {0, 0});
    /*we want:
    descent 1 : 2, 6
    descent 2: 0, 0
    descent 3: 2, 2
    descent 4: 0, 0
    descent 5: 0, 0
    */
    vector<int> parent(n + 1, -1);
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
        descent[i] = {x, y};
        return (x + y) % kMod;
    };
    // for(int i = 1; i < n; i++){
    //     dfs(i);
    // }
    dfs(1);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j != 0){
            ans[i] += (descent[j].first + descent[j].second + 1) % kMod;
            j = parent[j];
        }
        cout << "ans[" << i << "] is " << ans[i] << '\n';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        // cout << "Children of " << i << " are " << tree[i].first << ", " << tree[i].second << '\n';
        // cout << "Parent of " << i << " is " << parent[i] << '\n';
        cout << "Descent of " << i << " is " << descent[i].first << ", " << descent[i].second << '\n';
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