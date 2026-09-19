#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, s;
    long long l;
    cin >> n >> s >> l;

    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n - 1; i++) {
        long long a;
        cin >> a;
        pre[i + 1] = pre[i] + a;
    }
    auto dist = [&](int u, int v) -> long long {
        return abs(pre[u] - pre[v]);
    };
    int maxv = 1;
    for (int i = 1; i <= s; i++) {
        long long left = dist(i, s);
        if (left > l) continue;
        maxv = max(maxv, s - i + 1);
        int low = s + 1, high = n, best = s;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long right = dist(s, mid);
            long long cost = min(2 * left + right, left + 2 * right);
            if (cost <= l) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        maxv = max(maxv, best - i + 1);
    }
    for (int i = s; i <= n; i++) {
        if (dist(s, i) <= l) {
            maxv = max(maxv, i - s + 1);
        }
    }
    cout << maxv << "\n";
    return 0;
}
