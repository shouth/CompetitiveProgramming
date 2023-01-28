#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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

#pragma clang diagnostic pop

void solve()
{
    i64 Q;
    cin >> Q;

    auto offset = i64(0);
    auto bag = multiset<i64>();
    for (i64 _ = 0; _ < Q; ++_) {
        i64 q;
        cin >> q;

        if (q == 1) {
            i64 X;
            cin >> X;
            bag.emplace(X - offset);
        } else if (q == 2) {
            i64 X;
            cin >> X;
            offset += X;
        } else {
            cout << *bag.begin() + offset << endl;
            bag.erase(bag.begin());
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
