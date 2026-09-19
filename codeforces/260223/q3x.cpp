#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = 0;
    long long curr = 0;
    int base = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            curr = 1;
        } else {
            if (arr[i] <= arr[base] || arr[i] > arr[i - 1] + 1) {
                curr += (i + 1);
                base = i;
            }
        }
        total += curr;
    }
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}