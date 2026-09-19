#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
	cin >> n;
    double result = numbers::pi * n * n * 0.25;
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}