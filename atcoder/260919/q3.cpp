#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++){
	    int x;
		cin >> x;
	    pq.push(x);
		if(pq.size() > 3) pq.pop();
		if(i >= 2) cout << pq.top() << '\n';
	}
    return 0;
}
