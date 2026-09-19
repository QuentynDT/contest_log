#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    const int ans = max(x - y * n, 0);
    cout << ans << '\n';
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