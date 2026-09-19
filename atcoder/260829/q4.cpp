#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
	cin >> n >> k;
	vector<vector<int>> ans;
    vector<int> curr(n, 0);
	auto dfs = [&](this auto self, int i, int diff) -> void {
	    if(i == n){
			if(diff % n == 0){
			    curr[n - 1] = diff / n;
				ans.push_back(curr);
				curr[n - 1] = 0;
			}
			return;
		}
        if(diff < i){
            if(diff == 0) ans.push_back(curr);
            return;
        }
        for(int j = 0; j <= diff/i; j++){
            curr[i - 1] = j;
            self(i + 1, diff - (i * j));
        }
        curr[i - 1] = 0;
    };
	dfs(1, k);
	for(auto& v : ans){
	    for(auto& x : v){
			cout << x << ' ';
		}
		cout << '\n';
	}
    return 0;
}
