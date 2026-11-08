#include "../timer.h"

class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> order, parent(n, -1);
        order.push_back(0);
        for(vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
            }
        }
        vector<long long> sz(n, 1), pos(n, 0);
        long long red = 0, dec = 0;

        for (int i = n - 1; i >= 0; i--) {
            int v = order[i];
            long long w = -sz[v];
            if (colors[v] == 'R') {
                w = sz[v];
                red += sz[v];
            }
            long long best = w + pos[v];
            dec = max(dec, best);
            int p = parent[v];
            if (p != -1) {
                sz[p] += sz[v];
                pos[p] += max(0LL, best);
            }
        }
        return red - dec;
    }
};

struct token {
    int n;
    string colors;
    vector<vector<int>> edges;
    long long ans;
    long long res;
};

void handle(token& data) {
    Solution s;
    data.res = s.minCost(data.n, data.colors, data.edges);
}

void runTests(vector<token>& tokens) {
    cout << '\n';
    for(token& t : tokens) {
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main() {
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({3, "RBR", {{0, 1}, {1, 2}}, 1});

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
}
