#include "../timer.h"

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int x = 0;
        bool first = true;
        const int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i % 6 == 5){
                first = !first;
            }
            if(nums[i] % 2 == 1){
                first = !first;
            }
            x += first ? nums[i] : -nums[i];
        }
        return x;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.scoreDifference(data.nums);
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
    tokens[0] = {{2,4,2,1,2,1}, 4};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}