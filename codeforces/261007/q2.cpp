#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> st;
    vector<int> dead;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') st.push_back(i + 1);
        else if (s[i] == '2') {
            if(!st.empty()) {
                st.pop_back();
                dead.push_back(i + 1);
            }
        }
    }
    int stsz = st.size(), dsz = dead.size();
    int sz = stsz + dsz;
    cout << sz << '\n';
    int i = 0, j = 0;
    for(int k = 0; k < sz; k++){
        if(i == stsz) cout << dead[j++] << ' ';
        else if(j == dsz || st[i] < dead[j]) cout << st[i++] << ' ';
        else cout << dead[j++] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
	cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
