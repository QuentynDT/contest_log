#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long s, m;
    cin >> s >> m;
    long long low = m & -m;
    if (s % low != 0) {
        cout << -1 << "\n";
    } else {
        long long n = (s + m - 1) / m;
        cout << n << "\n";
    }
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