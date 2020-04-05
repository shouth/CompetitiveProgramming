#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<char, int> alla {
        { '1', 2 }, { '2', 5 }, { '3', 5 },
        { '4', 4 }, { '5', 5 }, { '6', 6 },
        { '7', 3 }, { '8', 7 }, { '9', 6 },
    };

    map<char, int> a;
    for (int i=0; i<m; i++) {
        char c;
        cin >> c;
        a[c] = alla[c];
    }

    auto compare = [&](string a, string b) -> int {
        if (a.size() > b.size()) return 1;
        if (a.size() < b.size()) return -1;

        for (int i = 0, e = a.size(); i < e; i++) {
            if (a[i] == b[i]) continue;
            if (a[i] > b[i]) return 1;
            if (a[i] < b[i]) return -1;
        }

        return 0;
    };

    vector<string> dp(n + 1);
    
    for (int i = 0; i < n; i++) {
        for (auto& e : a) {
            if (i + e.second > n || (dp[i].empty() && i != 0)) continue;
        
            if (compare(e.first + dp[i], dp[i + e.second]) == 1) {
                dp[i + e.second] = e.first + dp[i];
            }
        }
    }

    cout << dp[n] << endl;
}
