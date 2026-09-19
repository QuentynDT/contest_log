#include <bits/stdc++.h>

using namespace std;

const int kMod = 998244353;
void solve(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << '\n';
    vector<long long> left(n), right(n);
    left[0] = 1;
    for(int i = 1; i < n; i++){
        left[i] = lcm(arr[i - 1], left[i - 1]);
    }
    right[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        right[i] = lcm(arr[i + 1], right[i + 1]);
    }
    for(int i = 0; i < n; i++){
        cout << lcm(left[i], right[i] % kMod) << ' ';
    }
    cout << '\n';
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