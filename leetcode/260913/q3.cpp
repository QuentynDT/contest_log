#include "../timer.h"

struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (i++; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        const int n = nums.size();
        vector<int> r(n, n - 1);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                r[st.back()] = i - 1;
                st.pop_back();
            }
            st.push_back(i);
        }
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] > nums[b];
            return a < b;
        });
        FenwickTree bit(n);
        long long ans = 0;
        for (int i : order) {
            ans += bit.query(i + 1, r[i]);
            bit.add(i, 1);
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.shadowPairs(data.nums);
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
    vector<token> tokens;
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
