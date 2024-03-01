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

int64_t create_scc(int64_t s, int64_t c, int64_t scc = 0) {
    if (c == 0 || c == 1 || (s == 0 && c < 4)) {
        return scc;
    } else if (s == 0) {
        return create_scc(c / 4, c - c / 4 * 2, scc);
    } else if (s <= c / 2) {
        return create_scc(0, c - s * 2, scc + s);
    } else {
        return create_scc(s - c / 2, c - c / 2 * 2, scc + c / 2);
    }
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    cout << create_scc(n, m) << endl;
}
