#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    vector<vector<int>> sec(n + 1);
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        sec[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) s.insert({-cnt[i], i});
    for (int i = 1; i <= n; i++) {
        s.erase({-cnt[i], i});
        for (int j : sec[i]) {
            s.erase({-cnt[j], j});
            cnt[j]++;
            s.insert({-cnt[j], j});
        }
        cout << s.begin()->second << "\n";
        for (int j : sec[i]) {
            s.erase({-cnt[j], j});
            cnt[j]--;
            s.insert({-cnt[j], j});
        }
        s.insert({-cnt[i], i});
    }
    return 0;
}
