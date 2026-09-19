#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    cout << (n * 5 >= s ? 6 * n : 5 * (s - 5 * n) + 6 * (6 * n - s)) << '\n';
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