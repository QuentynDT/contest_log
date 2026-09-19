#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x = 1;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + a[i]; j < n; j+=a[i]){
            ans+= (1LL * a[i] * a[j] == 1LL * j - i);
        }
    }
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