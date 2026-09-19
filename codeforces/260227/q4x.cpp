#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> ans(n);
    int j = 0;
    bool idone = false;
    int index = min_element(arr.begin() + x, arr.begin() + y) - arr.begin();
    cout << index << " is index\n";
    auto ins = [&]() -> void {
        for(int i = x; i < y; i++){
            cout << i << ' ' << index << ' ' << (i + index - x) << " = " << (i - x + index - x) % (y - x) + x << '\n';
            ans[j++] = arr[(i - x + index - x) % (y - x) + x];
        }
        idone = true;
    };
    for (int i = 0; i < n; i++) {
        if(i >= x && i < y) continue;
        if(!idone && arr[i] > arr[index]) {
            
        cout << "ins has been called at " << i << '\n'; 
        ins();
        }
        ans[j++] = arr[i];
    }
    if(!idone) ins();
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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