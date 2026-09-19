#include "../timer.h"

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        unordered_map<int, int> freq;
        for(int& x : nums){
            freq[x]++;
            first = min(first, x);
        }
        for(int& x : nums){
            if(freq[x] == freq[first]) continue;
            second = min(second, x);
        }
        return second == INT_MAX ? vector<int>{-1, -1} : vector<int>{first, second};
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.minDistinctFreqPair(data.nums);
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
    tokens.push_back({{1,1,2,2,3,4}, {1,3}});
    tokens.push_back({{1,5}, {-1, -1}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}