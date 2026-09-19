#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
	cin >> n >> m;
    cout << ((n + 1) / 2 >= m ? "Yes" : "No") << "\n";
    return 0;
}