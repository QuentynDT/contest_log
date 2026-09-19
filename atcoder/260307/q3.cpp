#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 2;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int n) : n(n) {
        tree.assign(4 * n, INF);
    }
    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    int query() {
        return tree[1];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree st(n);
    st.build(a, 1, 0, n - 1);
    while (q--) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            st.update(1, 0, n - 1, b[i] - 1, INF);
        }
        cout << st.query() << "\n";
        for (int i = 0; i < k; i++) {
            st.update(1, 0, n - 1, b[i] - 1, a[b[i] - 1]);
        }
    }
    return 0;
}