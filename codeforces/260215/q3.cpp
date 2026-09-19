#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0, curr = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1] || arr[i] + arr[i + 1] == 7) {
            curr++;
        }
        else {
            ans += (curr + 1)/2;
            curr = 0;
        }
    }
    ans += (curr + 1)/2;
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