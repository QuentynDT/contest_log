#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(!st.empty() && s[i] == st.top()) st.pop();
        else st.push(s[i]);
    }
    cout << (st.empty() ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
	cin >> t;
    while(t--){
        solve();
    }
    return 0;
}