#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    string s, t;
	cin >> n >> s >> t;
	bool valid = true;
	for(int i = 0; i < n; i++){
	    if(t[i] != '*' && t[i] != s[i]){
			valid = false;
			break;
		}
	}
	if(valid) cout << "Yes\n";
	else cout << "No\n";
    return 0;
}
