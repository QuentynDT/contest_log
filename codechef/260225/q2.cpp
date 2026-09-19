#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    string s;
    cin >> s;
    priority_queue<int> h;

    for (int i = 0; i < n; i++) {
        if(s[i] == '1') continue;
        h.push(arr[i]);
        if (h.size() > k) {
            h.pop();
        }
    }
    if(h.size() < k){
        cout << "-1\n";
        return;
    }
    int ans = 0;
    while (!h.empty()) {
        ans += h.top();
        h.pop();
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