#include <bits/stdc++.h>

using namespace std;
//
void solve(){
    long long a, b;
    cin >> a >> b;
    if(a < 2 || b < 3 || a >= b || ( 2 * (b - a) > a)){
        cout << "Alice\n";
    } else {    
        cout << "Bob\n";
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