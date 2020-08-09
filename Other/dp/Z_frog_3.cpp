#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct convex_hull_trick {
    struct line {
        i64 a, b;
        i64 at(i64 x) { return a * x + b; }
    };

    deque<line> q_;

    bool validate(const line &a, const line &b, const line &c) {
        return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
    }

    void add(i64 a, i64 b) {
        line l { a, b };
        for (i64 n; n = q_.size(), n > 1 && validate(q_[n - 2], q_[n - 1], l);) {
            q_.pop_back();
        }
        q_.push_back(move(l));
    }

    i64 query(i64 x) {
        if (q_.empty()) return INF;
        while (q_.size() > 1 && q_[0].at(x) >= q_[1].at(x)) {
            q_.pop_front();
        }
        return q_[0].at(x);
    }
};

void solve() {
    i64 n, c;
    cin >> n >> c;

    i64 h;
    cin >> h;
    convex_hull_trick cht;
    cht.add(-2 * h, h * h);

    i64 dp = 0;
    for (i64 i = 1; i < n; i++) {
        cin >> h;
        dp = cht.query(h) + h * h + c;
        cht.add(-2 * h, dp + h * h);
    }
    cout << dp << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
