#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int64_t>> location(n+1, vector<int64_t>(10, n));
    for (int64_t i = n-1; i >= 0; i--) {
        for (int64_t x = 0; x <= 9; x++) location[i][x] = location[i+1][x];
        location[i][s[i]-'0'] = i;
    }

    map<string, int> ans;
    // 1: current string, 2: depth, 3: index
    queue<tuple<string, int, int>> q;
    q.emplace("", 0, 0);
    while (!q.empty()) {
        string str;
        int depth, index;
        tie(str, depth, index) = q.front(); q.pop();
        if (str.size() == 3) {
            ans[str]++;
            continue;
        }

        for (int x = 0; x <= 9; x++) {
            if (location[index][x] >= n) continue;
            q.emplace(str + (char) (x + '0'), depth+1, location[index][x]+1);
        }
    }
    
    cout << ans.size() << endl;
}
