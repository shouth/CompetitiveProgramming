#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 h, w, n;
    cin >> h >> w >> n;
    i64 sr, sc;
    cin >> sr >> sc;
    string s, t;
    cin >> s >> t;
    
    map<char, i64> cnt;
    bool f = true;
    for (i64 i = 0; i < n; i++) {
        cnt[s[i]]++;

        if (sc - cnt['L'] < 1 || sc + cnt['R'] > w
            || sr - cnt['U'] < 1 || sr + cnt['D'] > h) {
            f = false;
            break;
        }

        switch (t[i]) {
        case 'L':
            if (sc + cnt['R'] > 1) cnt['R']--;
            break;
        case 'R':
            if (sc - cnt['L'] < w) cnt['L']--;
            break;
        case 'U':
            if (sr + cnt['D'] > 1) cnt['D']--;
            break;
        case 'D':
            if (sr - cnt['U'] < h) cnt['U']--;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
