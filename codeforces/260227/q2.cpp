#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            cout << "1\n";
            return;
        }
    }
    cout << n << "\n";
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