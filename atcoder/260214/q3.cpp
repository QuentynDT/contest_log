#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
	cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    auto dfs = [&](this auto self, int i) -> int {
        if(i == arr[i]){
            return i; 
        } else {
            arr[i] = self(arr[i]);
            return arr[i];
        }
    };
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}