#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int64_t modpow(int64_t x, int64_t n) {
  int64_t ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto& e : d) cin >> e;

    if (d[0] == 0) {
        d.erase(begin(d));
        d.shrink_to_fit();
        map<int64_t, int64_t> m;
        for (auto& e : d) m[e]++;

        int64_t pk = 0, pv = 1;
        bool f = true;
        int64_t ans = 1;
        for (auto& e : m) {
            if (pk + 1 != e.first) {
                f = false;
                break;
            }

            ans *= modpow(pv, e.second);
            ans %= MOD;
            pk = e.first;
            pv = e.second;
        }

        if (f) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << 0 << endl;
    }
}
