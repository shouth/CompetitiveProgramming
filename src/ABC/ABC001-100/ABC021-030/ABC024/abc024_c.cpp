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
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> lr(d);
    for (auto& e : lr) cin >> e.first >> e.second;
    vector<pair<int, int>> st(k);
    for (auto& e : st) cin >> e.first >> e.second;

    vector<int> ans(k, -1);
    for (int i = 0; i < d; i++) {
        int l, r;
        tie(l, r) = lr[i];
        for (int j = 0; j < k; j++) {
            if (ans[j] != -1) continue;
            int s, t;
            tie(s, t) = st[j];
            if (s < l || r < s) continue;
            if (t < l || r < t) {
                st[j].first = s < t ? r : l;
            } else {
                ans[j] = i + 1;
            }
        }
    }

    for (auto& e : ans) cout << e << endl;
}
