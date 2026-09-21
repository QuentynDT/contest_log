#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
	cin >> s;
	string t;
	if(s[s.size() - 1] == 'e') s += 'r';
	else s += "er";
	cout << s << '\n';
    return 0;
}
