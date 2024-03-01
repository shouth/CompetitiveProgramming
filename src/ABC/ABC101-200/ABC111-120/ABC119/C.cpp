#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    for (auto& e : l) cin >> e;

    int ans = 1e9;
    stack<tuple<int, int, int, int, int>> s;
    s.emplace(0, 0, 0, 0, 0);
    while (!s.empty()) {
        auto t = s.top();
        s.pop();
        int ta, tb, tc, join, depth;
        tie(ta, tb, tc, join, depth) = t;
        if (depth == n) {
            if (ta != 0 && tb != 0 && tc != 0) ans = min(ans, join * 10 + abs(a - ta) + abs(b - tb) + abs(c - tc));
        } else {
            s.emplace(ta + l[depth], tb, tc, join + (ta != 0), depth + 1);
            s.emplace(ta, tb + l[depth], tc, join + (tb != 0), depth + 1);
            s.emplace(ta, tb, tc + l[depth], join + (tc != 0), depth + 1);
            s.emplace(ta, tb, tc, join, depth + 1);
        }
    }

    cout << ans << endl;
}
