#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    size_t mx = 0;
	cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i].size());
    }
    for(int i = 0; i < n; i++){
        const size_t d = (mx - arr[i].size())/2;
        const string gap(d, '.');
        cout << gap << arr[i] << gap << '\n';
    }
    return 0;
}