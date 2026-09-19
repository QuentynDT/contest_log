#include <bits/stdc++.h>

using namespace std;

void solve() {
    unsigned n;
    cin >> n;

    vector<unsigned> a(n);
    unsigned mx = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (mx == 0) {
        cout << 0 << '\n';
        return;
    }
    set<unsigned> s;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << mx << '\n';
            return;
        }
        unsigned shift = bit_width((mx / a[i])) - 1;
        s.insert(a[i] << shift);
    }
    const unsigned ceiling = min(mx, 1u << 30);
    unsigned mn = *s.rbegin() - *s.begin();
    while (true) {
        unsigned smallest = *s.begin();
        if (smallest > ceiling) break;
        s.erase(s.begin());
        s.insert(smallest * 2);
        mn = min(mn, *s.rbegin() - *s.begin());
    }
    cout << mn << '\n';
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