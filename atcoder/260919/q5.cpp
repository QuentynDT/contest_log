#include <bits/stdc++.h>

using namespace std;

struct Node {
    int min_val;
    int min_idx;
    int max_val;
    int max_idx;
};

class SegmentTree {
private:
    int n;
    vector<int> arr;
    vector<Node> tree;

    Node combine(const Node& left, const Node& right) {
        Node res;

        if (left.min_val <= right.min_val) {
            res.min_val = left.min_val;
            res.min_idx = left.min_idx;
        } else {
            res.min_val = right.min_val;
            res.min_idx = right.min_idx;
        }

        if (left.max_val >= right.max_val) {
            res.max_val = left.max_val;
            res.max_idx = left.max_idx;
        } else {
            res.max_val = right.max_val;
            res.max_idx = right.max_idx;
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], start, arr[start], start};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = {val, idx, val, idx};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {INT_MAX, -1, INT_MIN, -1};
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return combine(query(2 * node, start, mid, l, r),
                       query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    SegmentTree(const vector<int>& input_arr) {
        arr = input_arr;
        n = arr.size();
        tree.resize(4 * n);
        if (n > 0) build(1, 0, n - 1);
    }
    void update(int idx, int val) {
        arr[idx] = val;
        update(1, 0, n - 1, idx, val);
    }
    void swapAt(int i, int j) {
        if (i == j || i < 0 || j < 0 || i >= n || j >= n) return;
        swap(arr[i], arr[j]);
        update(1, 0, n - 1, i, arr[i]);
        update(1, 0, n - 1, j, arr[j]);
    }
    int get(int idx) const {
        return arr[idx];
    }
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, l, r;
    cin >> n >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    SegmentTree st(p);
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        Node res = st.query(l - 1, r - 1);
        st.swapAt(res.min_idx, res.max_idx);
    }
    for(int i = 0; i < n; i++){
        cout << st.get(i) << ' ';
    }
    cout << '\n';
    return 0;
}
