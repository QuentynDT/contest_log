#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << a % x + b + a / x * y << '\n';
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