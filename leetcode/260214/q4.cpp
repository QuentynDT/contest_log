#include "../timer.h"

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    int LOG;
    int timer;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, tin, tout, bit, current_masks;
    int parseNextInt(const string& s, size_t& pos) {
        while (pos < s.size() && (s[pos] < '0' || s[pos] > '9')) pos++;
        int res = 0;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
            res = res * 10 + (s[pos] - '0');
            pos++;
        }
        return res;
    }

    void update_bit(int idx, int val, int limit) {
        for (; idx <= limit; idx += idx & -idx)
            bit[idx] ^= val;
    }

    int query_bit(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];
        return res;
    }

    void initialize_tree(int n, const string& s) {
        timer = 0;
        stack<int> st;
        st.push(0);
        vector<bool> visited(n, false);
        
        while (!st.empty()) {
            int v = st.top();
            if (!visited[v]) {
                visited[v] = true;
                tin[v] = ++timer;
                for (int u : adj[v]) {
                    if (u != up[v][0]) {
                        up[u][0] = v;
                        depth[u] = depth[v] + 1;
                        st.push(u);
                    }
                }
            } else {
                tout[v] = ++timer;
                st.pop();
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        int limit = n * 2;
        for (int i = 0; i < n; i++) {
            int m = (1 << (s[i] - 'a'));
            current_masks[i] = m;
            update_bit(tin[i], m, limit);
            update_bit(tout[i], m, limit);
        }
    }

    int get_lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[a] - (1 << i) >= depth[b]) a = up[a][i];
        }
        if (a == b) return a;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        LOG = (n > 1) ? 32 - __builtin_clz(n) : 1;
        adj.assign(n, vector<int>());
        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(2 * n + 1, 0);
        current_masks.assign(n, 0);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        initialize_tree(n, s);

        vector<bool> ans;
        for (const string& q : queries) {
            size_t pos = 0;
            if (q[0] == 'u') {
                pos = 7;
                int idx = parseNextInt(q, pos);
                while (pos < q.size() && (q[pos] < 'a' || q[pos] > 'z')) pos++;
                int next_mask = (1 << (q[pos] - 'a'));
                update_bit(tin[idx], current_masks[idx] ^ next_mask, 2 * n);
                update_bit(tout[idx], current_masks[idx] ^ next_mask, 2 * n);
                current_masks[idx] = next_mask;
            } else {
                int u = parseNextInt(q, pos);
                int v = parseNextInt(q, pos);
                int lca = get_lca(u, v);
                int path_xor = query_bit(tin[u]) ^ query_bit(tin[v]) ^ current_masks[lca];
                ans.push_back(__builtin_popcount(path_xor) <= 1);
            }
        }
        return ans;
    }
};

struct token {
    int n;
    vector<vector<int>> edges;
    string s;
    vector<string> queries;
    vector<bool> ans;
    vector<bool> res;
};

void handle(token& data){
    Solution s;
    data.res = s.palindromePath(data.n, data.edges, data.s, data.queries);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main(){
    const int n = 1;
    vector<token> tokens(n);
    tokens[0] = {4, {{0, 1}, {0, 2}, {0, 3}}, "abca", {"query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"}, {false, false, true}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}