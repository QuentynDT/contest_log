#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    if(k < n || k >= 2 * n){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int l = k - n + 1;
    vector<int> arr(2 * n);
    for(int i = 0; i < min(3, 2 * n); i++){
        arr[i] = i + 1;
    }
    for(int i = 2; i < 2 * l - 2; i+=2){
        arr[i + 1] = arr[i] - 2;
        arr[i + 2] = arr[i] + 1;
    }
    if(l > 1) {
        arr[2 * l - 2] = l - 1;
    }
    arr[2 * l - 1] = l;
    for(int i = 2 * l; i < 2 * n; i++){
        arr[i] = 1 + i / 2;
    }
    for(int i = 0; i < 2 * n; i++){
        cout << arr[i] << ' ';
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