#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    long long k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    ranges::sort(a);
    ranges::sort(b);
    vector<long long> pa(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pa[i + 1] = pa[i] + a[i];
    }
    auto maxd = [&](long long cash) {
        auto it = upper_bound(pa.begin(), pa.end(), cash);
        return distance(pa.begin(), it) - 1;
    };
    long long ans = maxd(x + y * k), d = 0;
    for (int i = 0; i < m; i++) {
        long long kn = 1 + (b[i] - 1) / k;
        if(y < kn) break;
        y -= kn;
        x += (kn * k - b[i]);
        ans = max(ans, ++d + maxd(x + y * k));
    }
    cout << ans << "\n";

    return 0;
}
