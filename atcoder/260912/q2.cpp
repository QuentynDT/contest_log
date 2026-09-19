#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x, a = 0, b = 0, c = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
        cin >> x;
        x = (1000 - (x % 1000)) % 1000;
        a += x % 10;
        x /= 10;
        b += x % 10;
        x /= 10;
        c += x;
	}
	cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
