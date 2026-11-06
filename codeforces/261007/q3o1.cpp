#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<unordered_map<int, int>> cross(6 + n);
    vector<unordered_map<int, int>> dp(6 + n);
    unordered_set<int> seen;
    for(int i = 0; i < n - 4; i++){
        int love = a[i] + a[i + 2] - a[i + 4];
        seen.insert(love);
        cout << "inserting " << love << '\n';
        dp[i + 10][love] = 1 + max({dp[i + 4][love], dp[i + 2][love], dp[i][love]});
        cross[i % 2][love]++;
    }
    long long ans = 0;
    for(auto& x : seen){
        int a = dp[4 + n][x];
        int b = dp[5 + n][x];
        long long same = (1LL * (a * (a - 1) + b * (b - 1))) / 2;
        ans += 1LL * cross[0][x] * cross[1][x] + same;
        cout << "for " << x << ", " << cross[0][x] << " * " << cross[1][x] << " + " << same << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
	cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
