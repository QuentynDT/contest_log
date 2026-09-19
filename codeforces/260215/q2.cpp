#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] == i) continue;
        int j = 2 * i;
        while(j <= n){
            if(arr[j] == i){
                swap(arr[j], arr[i]);
                break;
            }
            j *= 2;
        }
        if(arr[i] != i){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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