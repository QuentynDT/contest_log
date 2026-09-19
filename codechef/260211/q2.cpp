#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    bool ans = true;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans ^= (x % 2);
    }
    if(ans){
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