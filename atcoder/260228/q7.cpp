#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> k(n);
    vector<int> a(n);
    vector<vector<pair<int, int>>> km(n);
    for(int i = 0; i < n; i++){
        cin >> k[i] >> a[i];
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        km[k[i] - 1].emplace_back(a[i], i);
    }
    vector<pair<int, int>> bestleft(n, {-1, -1});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(int i = 2; i < n - 2; i++){
        for(int j = 0; j < i; j++){
            if(k[j] == k[i]) continue;
            minHeap.push({a[j], j});
            if(minHeap.size() > 2){
                minHeap.pop();
            }
        }
        if(minHeap.empty()) continue;
        //cout << "Top: " << minHeap.top().first << " " << minHeap.top().second << '\n';
        bestleft[i].second = minHeap.top().second;
        minHeap.pop();
        if(minHeap.empty()) continue;
        //cout << "Top: " << minHeap.top().first << " " << minHeap.top().second << '\n';
        bestleft[i].first = minHeap.top().second;
        minHeap.pop();
        if(!minHeap.empty()) cout << "how the hell!\n";
    }
    for(int i = 2; i < n - 2; i++){
        cout << "for " << i << ": " << bestleft[i].first << ", " << bestleft[i].second << '\n';
    }
    // for(int i = 2; i < n - 3; i++){
    //     for(int j = i + 1; j < n - 2; j++){
    //         cout << i << ' ' << j << '\n';
    //     }
    // }
    return 0;
}