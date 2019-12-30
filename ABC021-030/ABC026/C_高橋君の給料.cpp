#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>> b;

int dfs(int e) {
    if (b.find(e) == b.end()) return 1;
    
    int maxs = 0, mins = 1e9;
    for (auto& sub : b[e]) {
        int tmp = dfs(sub);
        maxs = max(maxs, tmp), mins = min(mins, tmp);
    }

    return maxs + mins + 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;
        b[e].push_back(i);
    }
    
    cout << dfs(1) << endl;
}
