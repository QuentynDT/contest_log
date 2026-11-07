#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n + 1), p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    vector<long long> pmax(n + 1), pmin(n + 1), smax(n + 1), smin(n + 1);
    pmax[0] = pmin[0] = 0;
    for (int i = 1; i <= n; i++) {
        pmax[i] = max(pmax[i - 1], p[i]);
        pmin[i] = min(pmin[i - 1], p[i]);
    }
    smax[n] = smin[n] = p[n];
    for (int i = n - 1; i >= 0; i--) {
        smax[i] = max(smax[i + 1], p[i]);
        smin[i] = min(smin[i + 1], p[i]);
    }
    long long ans = pmax[n] - pmin[n] + 1;
    for (int i = 1; i <= n; i++) {
        long long hi = max(pmax[i - 1], smax[i] - 2 * a[i]);
        long long lo = min(pmin[i - 1], smin[i] - 2 * a[i]);
        ans = max(ans, hi - lo + 1);
    }
    cout << ans << "\n";
    return 0;
}
