#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    unordered_map<int, int> seq;
    seq.reserve(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        seq[arr[i]] = 1 + seq[arr[i] - 1];
        mx = max(mx, seq[arr[i]]);
    }
    cout << mx << '\n';
    return 0;
}