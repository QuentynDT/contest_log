#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
	cin >> n;
	int b, c, x = 0;
	for(int i = 0; i < n/2; i++) cin >> b;
	for(int i = 0; i < n/2; i++) {
	    cin >> c;
		x+= c;
	}
	cout << x << '\n';
    return 0;
}
