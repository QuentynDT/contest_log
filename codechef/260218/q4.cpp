#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> first(n + 1, -1);
    vector<int> afreq(n + 1, 0);
    vector<int> tfreq(n + 1, 0);
    for(int i = n; i > 0; i--){
        first[arr[i]] = i;
        tfreq[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(i > first[arr[i]]){
            afreq[arr[i]]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(tfreq[i] == 0) continue;
        // cout << "The first occurrence of " << i << " is " << first[i] << '\n';
        // cout << i << " is seen " << afreq[i] << " times after the first occurrence\n";
        int x = min(n - first[i] - afreq[i], k) + tfreq[i];
        ans = max(ans, x);

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