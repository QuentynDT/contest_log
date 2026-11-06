#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<pair<long long, int>> list;
    for(int i = 0; i < n; i++){
        long long sum = a[i] + b[i] + c[i];
        list.emplace_back(sum, i);
    }
    ranges::sort(list);
    long long ans = 0,  mp = 1;
    for(int j = 0; j < n; j++){
        int i = list[j].second;
        long long sum = a[i] + b[i] + c[i];
        if(a[i] == b[i] && a[i] == c[i]){
            ans = sum;
            break;
        }
        if(a[i] <= b[i] && b[i] <= c[i]) {
            long long loss = min({b[i] - a[i], c[i] - b[i], c[i] - a[i]}) + 1;
            if(k <= 2 * loss){
                ans = sum;
                break;
            } else {
                k -= 2 * loss;
            }
        }
        if(j != n - 1){
            long long gap = list[j + 1].first - list[j].first;
            long long distance = mp * gap;
            if(k > distance){
                mp++;
                k -= distance;
                continue;
            } else {
                long long minwalk = k / mp;
                ans = minwalk + sum;
                break;
            }
        } else {
            long long minwalk = k / n;
            ans = minwalk + sum;
            break;
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
