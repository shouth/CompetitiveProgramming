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

constexpr int64_t MOD = 1e9 + 7;

int64_t n;
vector<vector<int64_t>> ab;
vector<int64_t> wdp, bdp, visit;

pair<int64_t, int64_t> dfs(int64_t i) {
    if (wdp[i] != -1) return make_pair(wdp[i], bdp[i]);
    visit[i] = 1;

    int64_t wres = 1, bres = 1;
    for (auto& e : ab[i]) {
        if (visit[e]) continue;
        int64_t wtmp, btmp;
        tie(wtmp, btmp) = dfs(e);
        wres *= wtmp + btmp % MOD, wres %= MOD;
        bres *= wtmp % MOD, bres %= MOD;
    }

    return make_pair(wdp[i] = wres, bdp[i] = bres);
}

int main() {
    cin >> n;
    ab.resize(n);
    wdp.resize(n, -1);
    bdp.resize(n, -1);
    visit.resize(n);
    for (int64_t i = 0; i < n-1; i++) {
        int64_t a, b;
        cin >> a >> b, a--, b--;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }

    auto ans = dfs(0);
    cout << (ans.first + ans.second) % MOD << endl;
}
