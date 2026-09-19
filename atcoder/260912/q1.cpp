#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
	cin >> s;
	string t;
	const int n = s.size() - 1;
	for(int i = 0; i < n; i++){
	    t += s[i];
		t += 'o';
	}
	t += s[n];
	cout << t << '\n';
    return 0;
}
