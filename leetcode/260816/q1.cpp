#include "../timer.h"

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        const int n = drones.size();
        int di = -1, mind = INT_MAX;
        for(int i = 0; i < n; i++){
            int d = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(d < drones[i][2] && d < mind){
                mind = d;
                di = i;
            }
        }
        return di;
    }
};

struct token {
    vector<vector<int>> drones;
    vector<int> target;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.nearestDrone(data.drones, data.target);
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
    const int n = 3;
    vector<token> tokens;
    tokens.push_back({{{0,0,8},{2,2,9}}, {3, 4}});
    tokens.push_back({});
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
