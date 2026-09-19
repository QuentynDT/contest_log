#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k, x;
    cin >> n >> k;
    unordered_set<int> seen;
    seen.insert(0);
    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pre = (pre + x) % k;
        if (seen.contains(pre)) {
            ans++;
            seen.clear();
            seen.insert(0);
            pre = 0;
        } else {
            seen.insert(pre);
        }
    }
    cout << ans << '\n';
}
