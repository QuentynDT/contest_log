#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int x;
	cin >> x;
	const int ans = min(300, 100 + 4 * x);
	cout << ans << '\n';
}