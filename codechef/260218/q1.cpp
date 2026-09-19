#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, a;
	cin >> n >> m >> a;
	if(n * a < m){
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}