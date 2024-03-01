#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

void solve() {
    i64 N;
    cin >> N;
    auto ab = vector<complex<double>>(N);
    auto cent_ab = complex<double>();
    for (auto &comp : ab) {
        double a, b;
        cin >> a >> b;
        comp = { a, b };
        cent_ab += comp;
        comp *= N;
    }
    for (auto &comp : ab) {
        comp -= cent_ab;
    }
    auto cd = vector<complex<double>>(N);
    auto cent_cd = complex<double>();
    for (auto &comp : cd) {
        double c, d;
        cin >> c >> d;
        comp = { c, d };
        cent_cd += comp;
        comp *= N;
    }
    for (auto &comp : cd) {
        comp -= cent_cd;
    }

    if (N == 1) {
        cout << "Yes" << endl;
        return;
    }

    auto itr = find_if(begin(ab), end(ab), [&](auto e) { return abs(e) != 0; });
    auto flag = any_of(begin(cd), end(cd), [&](auto arg) {
        arg /= *itr, arg /= abs(arg);
        return all_of(begin(ab), end(ab), [&](auto p) {
            p *= arg;
            return any_of(begin(cd), end(cd), [&](auto q) {
                return abs(p - q) < 1e-6;
            });
        });
    });
    cout << (flag ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
