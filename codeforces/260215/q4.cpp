#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<long long> f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    int x = f[0], y = f[n - 1];
    for(int i = 1; i < n - 1; i++){
        ans[i] = (f[i + 1] + f[i - 1] - 2 * f[i])/2;
        x -= ans[i] * i;
        y -= ans[i] * (n - i - 1);
    }
    ans[n - 1] = x / (n - 1);
    ans[0] = y / (n - 1);
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
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