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
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    t = string(k, '_') + t;

    int ans = 0;
    for (int i = k; i < (int) t.size(); i++) {
        if (t[i-k] == t[i]) {
            t[i] = '_';
            continue;
        }

        switch (t[i]) {
        case 'r':
            ans += p;
            break;
        case 's':
            ans += r;
            break;
        case 'p':
            ans += s;
            break;
        }
    }

    cout << ans << endl;
}
