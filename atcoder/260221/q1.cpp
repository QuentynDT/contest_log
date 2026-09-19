#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
	cin >> s;
    s[0] = tolower(s[0]);
    string ans = "Of" + s;
    cout << ans << '\n';
    return 0;
}