#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    const int d = a - b;
    if (n >= a) {
        n -= ((n - a) / d + 1) * d;
    }
    cout << n << '\n';
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