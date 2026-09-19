#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x, ans = 0;
	cin >> n;
	vector<bool> seen(100, false);
	for(int i = 0; i < n; i++){
	    cin >> x;
		if(seen[x]){
		    ans -= x;
			seen[x] = false;
		} else {
		    ans += x;
			seen[x] = true;
		}
	}
	cout << ans << '\n';
	return 0;
}
