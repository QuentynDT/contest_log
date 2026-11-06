#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_set<int> seen;
    unordered_map<int, vector<int>> even_pos, odd_pos;
    for(int i = 0; i < n - 4; i++){
        int love = a[i] + a[i + 2] - a[i + 4];
        seen.insert(love);
        if (i % 2 == 0) even_pos[love].push_back(i);
        else odd_pos[love].push_back(i);
    }
    long long ans = 0;
    for(int love : seen){
        const auto& evens = even_pos[love];
        const auto& odds = odd_pos[love];
        const int e = evens.size(), o = odds.size();
        ans += 1LL * e * o;
        for(int i = 0; i < e; i++){
            auto it = upper_bound(evens.begin(), evens.begin() + i, evens[i] - 6);
            ans += (it - evens.begin());
        }
        for(int i = 0; i < o; i++){
            auto it = upper_bound(odds.begin(), odds.begin() + i, odds[i] - 6);
            ans += (it - odds.begin());
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
