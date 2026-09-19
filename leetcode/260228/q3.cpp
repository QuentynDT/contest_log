#include "../timer.h"

class Solution {
public:
    int ops(vector<int> nums){
        const int n = nums.size();
        int o = 0;
        for(int i = 1; i < n; i++){
            if((nums[i] - nums[i - 1]) % 2 == 0){
                nums[i]--;
                o++;
            }
        }
        return o;
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        const int n = nums.size();
        vector<int> v(2);
        v[0] = ops(nums);
        nums[0]--;
        v[1] = 1 + ops(nums);
        nums[0]++;
        int index = ranges::min_element(v) - v.begin();
        const int mx = ranges::max_element(nums) - nums.begin(), mn = ranges::min_element(nums) - nums.begin();
        if(v[index] == 0){
            v[0] = 0;
            v[1] = nums[mx] - nums[mn];
            return v;
        }
        if(nums[mn] == nums[mx]){
            v[0] = v[index];
            v[1] = 1;
            return v;
        }
        int ans = INT_MAX;
        for(int i = 0; i < 2; i++){
            if(v[i] > v[index]) continue;
            int mxval = nums[mx], mnval = nums[mn];
            for(int i = 0; i < n; i++){
                if(nums[i] == nums[mx]){
                    if(((i + nums[i]) % 2) != ((index + nums[index]) % 2)) mxval = nums[mx] - 1;
                    else mxval = min(mxval, nums[mx]);
                }
                if(nums[i] == nums[mn]){
                    if(((i + nums[i]) % 2) != ((index + nums[index]) % 2)) mnval = nums[mn] + 1;
                    else mnval = max(mnval, nums[mn]);
                }
            }
            ans = min(ans, mxval - mnval);
        }
        v[0] = v[index];
        v[1] = ans;
        return v;
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.makeParityAlternating(data.nums);
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
    tokens.push_back({{-2,-3,1,4}, {2,6}});
    tokens.push_back({{7, 7}, {1, 1}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}