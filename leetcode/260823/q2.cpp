#include "../timer.h"

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        auto it = lower_bound(nums.begin(), nums.end(), lower);
        int pos = it - nums.begin();
        const int n = nums.size();
        vector<vector<int>> ans;
        int start = -1, end = -1;
        for(int i = lower; i <= upper; i++){
            if(pos < n && nums[pos] == i){
                while (pos < n && nums[pos] == i) pos++;
                if(start != -1){
                    end = i - 1;
                    ans.push_back({start, end});
                    end = -1;
                    start = -1;
                }
            } else {
                if(start == -1){
                    start = i;
                }
            }
        }
        if(start != -1){
            end = upper;
            ans.push_back({start, end});
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int lower;
    int upper;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.findDisappearedNumbers(data.nums, data.lower, data.upper);
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
    tokens.push_back({{3,9,7}, 1, 12, {{1, 2}, {4, 6}, {8, 8}, {10, 12}}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
