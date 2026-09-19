#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n;
    bool sixseven = false;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 67) sixseven = true;
    }
    if(sixseven){
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