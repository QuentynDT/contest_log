#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> nd = {a[0]};
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            nd.push_back(a[i]);
        }
    }
    const int sz = nd.size();
    int j = 0;
    for(int i = 0; i < n && j < sz; i++){
        if(p[i] == nd[j]){
            j++;
        }
    }
    if(j == sz){
        cout << "Yes\n";
    } else {    
        cout << "No\n";
    }
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