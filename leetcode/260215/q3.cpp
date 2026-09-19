#include "../timer.h"
  
class Solution {
public:
    bool isPal(string s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++, r--;
        }
        return true;
    }
    int almostPalindromic(string s) {
        if(isPal(s)) return s.size();
        string t = "$$_";
        for(char& c : s){
            t += c;
            t += '_';
        }
        t+= "^^";
        const int n = t.size();
        vector<int> res(n, -1);
        for(int i = 2; i < n - 2; i++){
            int l = i, r = i, done = 0;
            while(true){
                if(t[l] != t[r]){
                    done++; 
                }
                l--;
                r++;
                if(done == 2) {
                    res[i] = l + 2;
                    break;
                }
            }
        }
        int mx = 0;
        for(int i = 2; i < n - 2; i++){
            int d = i - res[i];
            mx = max(mx, d);
        }
        return mx;
    }
};
 
struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.almostPalindromic(data.s);
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
    vector<token> tokens(n);
    tokens[0] = {"abca", 4};
    tokens[1] = {"abba", 4};
    tokens[2] = {"zzabba", 5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}