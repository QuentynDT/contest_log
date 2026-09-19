#include <bits/stdc++.h>

using namespace std;
int d(int y){
    int d = 0;
    while(y){
        d += y % 10;
        y/=10;
    }
    return d;
}
void solve(){
    int x, ans = 0;
    cin >> x;
    for(int y = x; y < x + 90; y++){
        if(y - d(y) == x){
            ans++;
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