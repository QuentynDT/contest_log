#include "../timer.h"
const int MAXN = 100000;
vector<int> spf(MAXN + 1);
bool done = false;
void buildSPF() {
    done = true;
    for (int i = 0; i <= MAXN; i++) spf[i] = i;

    for (int i = 2; 1LL * i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
class Solution {
public:


    vector<int> distinctPrimeFactors(int n) {
        vector<int> factors;

        while (n > 1) {
            int p = spf[n];
            factors.push_back(p);

            while (n % p == 0)
                n /= p;
        }

        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        if(!done) buildSPF();
        const int n = nums.size();
        vector<vector<int>> pfs(n);
        for(int i = 0; i < n; i++){
            pfs[i] = distinctPrimeFactors(nums[i]);
        }
        int ans = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        for(; r < n; r++){
            for(int j = 0; j < pfs[r].size(); j++){
                mp[pfs[r][j]]++;
            }
            while(mp.size() > k){
                for(int j = 0; j < pfs[l].size(); j++){
                    mp[pfs[l][j]]--;
                    if(mp[pfs[l][j]] == 0) mp.erase(pfs[l][j]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestSubarray(data.nums, data.k);
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
    tokens.push_back({{7, 6, 10, 12, 11}, 3, 3});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
