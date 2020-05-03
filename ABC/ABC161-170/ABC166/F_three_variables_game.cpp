#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

i64 n, a, b, c;
vector<string> ss;
vector<char> ans;
set<tuple<i64, i64, i64, i64>> dp;

bool dfs(i64 depth, i64 x, i64 y, i64 z) {
    if (dp.find({ depth, x, y, z }) != dp.end()) return false;
    if (x < 0 || y < 0 || z < 0) return false;
    if (depth == n) return true;

    i64 na, nb, nc;
    if (ss[depth] == "AB") {
        na = x + 1, nb = y - 1, nc = z;
    } else if (ss[depth] == "AC") {
        na = x + 1, nb = y, nc = z - 1;
    } else {
        na = x, nb = y + 1, nc = z - 1;
    }

    ans.push_back(ss[depth][0]);
    if (dfs(depth + 1, na, nb, nc)) return true;
    ans.pop_back();

    if (ss[depth] == "AB") {
        na = x - 1, nb = y + 1, nc = z;
    } else if (ss[depth] == "AC") {
        na = x - 1, nb = y, nc = z + 1;
    } else {
        na = x, nb = y - 1, nc = z + 1;
    }

    ans.push_back(ss[depth][1]);
    if (dfs(depth + 1, na, nb, nc)) return true;
    ans.pop_back();

    dp.emplace(depth, x, y, z);
    return false;
}

void solve() {
    cin >> n >> a >> b >> c;
    ss.resize(n);
    for (auto& e : ss) cin >> e;

    if (dfs(0, a, b, c)) {
        cout << "Yes" << endl;
        for (auto& e : ans) cout << e << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
