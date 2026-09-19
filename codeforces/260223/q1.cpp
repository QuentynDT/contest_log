#include <bits/stdc++.h>

using namespace std;
void solve(){
    int x, y;
    cin >> x >> y;
    const int d = x - 2*y;
    
    if (d % 3 != 0 || d < 0) {
        cout << "No\n";
        return;
    }
    const int e = d / 3, c = max(0, -y);
    if (c * 2 <= e) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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