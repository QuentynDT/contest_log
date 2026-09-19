#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0, count = 0, x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > mx){
            mx = x;
            count = 1;
        } else if (x == mx){
            count++;
        }
    }
    cout << count << "\n";
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