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

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto& e : p) cin >> e;
    for (auto& e : q) cin >> e;
    if (!lexicographical_compare(begin(p), end(p), begin(q), end(q))) swap(p, q);

    int ans = 0;
    while (lexicographical_compare(begin(p), end(p), begin(q), end(q))) {
        next_permutation(begin(p), end(p));
        ans++;
    }
    cout << ans << endl;
}
