#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    cout << (n - 1)/(1 + (d/m)) + 1 << '\n';
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