#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

bool is_agc(string str) {
    vector<string> tests = { str };
    for(int i=0; i<str.size()-1; i++) {
        string tmp = str;
        swap(tmp[i], tmp[i+1]);
        tests.push_back(tmp);
    }
    return any_of(tests.begin(), tests.end(), [&](auto test) {
        return (test.find("AGC") != string::npos);
    });
}

int main() {
    int n;
    cin >> n;

    vector<map<string, int>> dp(n+1, map<string, int>());
    dp[0]["TTT"] = 1;

    for (int i=0; i<n; i++) {
        for (auto last : dp[i]) {
            for (auto e : { 'A', 'C', 'G', 'T' }) {
                string next = last.first + e;
                if (!is_agc(next)) (dp[i+1][next.substr(1, 3)] += last.second) %= MOD;
            }
        }
    }
    
    int64_t ans = 0;
    for (auto e : dp[n]) {
        (ans += e.second) %= MOD;
    }
    cout << ans << endl;
}
