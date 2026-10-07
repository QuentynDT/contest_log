#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
	cin >> s;
	string t;
	if(s[s.size() - 1] == 'e') s += 'r';
	else s += "er";
	cout << s << '\n';
    return 0;
}
