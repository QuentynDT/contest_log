#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
	cin >> n >> m;
    vector<int> c(m);
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    vector<int> a(n), b(n), p(m);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        p[a[i] - 1] += b[i];
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        ans += min(c[i], p[i]);
    }
    cout << ans << '\n';
    return 0;
}