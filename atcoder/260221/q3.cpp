#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        q.emplace(a[i], i);
        while(q.front().first <= b[i]){
            b[i] -= q.front().first;
            q.pop();
            if(q.empty()) break;
        }
        if(q.empty()) continue;
        q.front().first -= b[i];
        while(q.front().second + d <= i){
            q.pop();
        }
    }
    int ans = 0;
    while(!q.empty()){
        ans += q.front().first;
        q.pop();
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