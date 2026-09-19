#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    long long ans = 0;
    vector<vector<int>> arr(26);
    vector<int> pl(26, 0), pr(26, 0);
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        arr[x].push_back(i);
        while (pl[x] < arr[x].size() && arr[x][pl[x]] < i - r) {
            pl[x]++;
        }
        while (pr[x] < arr[x].size() && arr[x][pr[x]] <= i - l) {
            pr[x]++;
        }

        ans += 1LL * (pr[x] - pl[x]);
    }
    cout << ans << '\n';
    return 0;
}