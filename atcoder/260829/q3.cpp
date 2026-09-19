#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k, x, mx = 0, ans = 0;
	cin >> n >> k;
	unordered_map<int, int> seen;
	for(int i = 0; i < n; i++){
	    cin >> x;
		seen[x]++;
	}
	for(auto& [x, y] : seen){
	    mx = max(mx, y);
	}
	for(auto& [x, y] : seen){
	    if(y + 1 >= mx) ans++;
	}
	cout << ans << '\n';
    return 0;
}
