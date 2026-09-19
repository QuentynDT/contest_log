#include "../timer.h"

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_set<int> twoseen;
        int ans = 0;
        const int n = nums.size();
        for(int i = 1; i <= n; i++){
            int x = nums[i - 1];
            if(i == n || x != nums[i]){
                if(!seen.contains(x)){
                    seen.insert(x);
                    ans++;
                } else if (!twoseen.contains(x)) {
                    twoseen.insert(x);
                    ans--;
                }
            }
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.countSpecialIntegers(data.nums);
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
    const int n = 2;
    vector<token> tokens;
    tokens.push_back({{1, 2, 2, 1}, 1});
    tokens.push_back({{9,62,62,75,75,75,96,96,96,96,96,96,96,96,9,9,9,9,9,75,75,75,9,9}, 2});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
