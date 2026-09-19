#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
	cin >> s;
    int ans = 0, sz = 1;
    bool rep = false;
    for(int i = 0; i < n; i++){
        if(i == n - 1 || s[i] != s[i + 1]){
            ans++;
            sz = 1;
        } else {
            rep = true;
            sz++;
        }
    }
    if(ans > 1 && s[0] != s[n - 1] && rep) ans++;
    cout << ans << "\n";
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