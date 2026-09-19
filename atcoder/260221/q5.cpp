#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m, a, b, ans = 0;
    cin >> m >> a >> b;
    vector<vector<int>> state(m, vector<int>(m, 0)); // 0 -> unknown, 1 -> success, 2 -> fail, 3 -> current

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < m; j++) {
            if (state[i][j]) {
                if (state[i][j] == 1) ans++;
                continue;
            }

            vector<pair<int, int>> path;
            int x = i, y = j;
            int outcome = 1; 

            while (true) {
                if (x == 0 || y == 0 || state[x][y] == 2) { 
                    outcome = 2;
                    break;
                } 
                if (state[x][y] == 1 || state[x][y] == 3) {
                    outcome = 1;
                    break;
                }
                state[x][y] = 3;
                path.emplace_back(x, y);
                int z = (b * x + a * y) % m;
                x = y;
                y = z;
            }
            for (auto& [x, y] : path) {
                state[x][y] = outcome;
            }
            if (outcome == 1) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}