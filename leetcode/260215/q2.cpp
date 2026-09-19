#include "../timer.h"

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> freqfreq;
        for(int& num : nums){
            freq[num]++;
        }
        for(auto& [x, fr] : freq){
            freqfreq[fr]++; 
        }
        for(int& num : nums){
            if(freqfreq[freq[num]] == 1) return num;
        }
        return -1;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.firstUniqueFreq(data.nums);
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
    tokens[0] = {{20,20,10,30,30,30}, 20};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}