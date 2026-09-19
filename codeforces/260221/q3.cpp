#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    const int sum = accumulate(arr.begin(), arr.end(), 0), rem = h % sum, div = h / sum;
    int ans;
    if(rem == 0){
        ans = div * n + (div - 1) * k;
    } else {
        vector<int> mins(n), maxs(n);
        mins[0] = arr[0], maxs[n - 1] = arr[n - 1];
        for(int i = 1; i < n; i++){
            mins[i] = min(mins[i - 1], arr[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            maxs[i] = max(maxs[i + 1], arr[i]);
        }
        int curr = 0, i = 0;
        for(i = 0; i < n - 1; i++){
            curr += arr[i];
            if(curr + max(0, maxs[i + 1] - mins[i]) >= rem){
                //cout << "You can deal " << curr << " + " << maxs[i] << " + " << mins[i] << " damage in just " << i + 1 << " shots\n";
                break;
            }
        }
        ans = div * (n + k) + i + 1;
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