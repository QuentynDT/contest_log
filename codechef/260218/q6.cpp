#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ans = 0, limit = -1; 
    cin >> n;
    vector<int> a(n), last(n + 2, -1), pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            pre[i + 1] = pre[i] + 1;
            limit = i;
        } else {
            if (a[i] > n || last[a[i] - 1] == -1) {
                pre[i] = 0;
                limit = -1;
            } else {
                pre[i + 1] = pre[i];
                limit = min(limit, last[a[i] - 1]);
            }
        }
        last[a[i]] = i;
        ans += pre[i];
        //cout << pre[i] << '\n';
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}