#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
	cin >> n >> q;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	auto func = [&](int x) -> void {
		for(int j = 0; j < x/2; j++){
		    int temp = v[j];
			v[j] = -v[x - j - 1];
			v[x - j - 1] = -temp;
		}
		if(x % 2 == 1) v[x / 2] = -v[x / 2];
	};
	for(int i = 0; i < q; i++){
	    int x;
		cin >> x;
		func(x);
	}
	for(int j = 0; j < n; j++){
	    cout << v[j] << '\n';
	}
    return 0;
}
