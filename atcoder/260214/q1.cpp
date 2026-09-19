#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
	cin >> s;
	if(s[0] == s[s.size() - 1]){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}