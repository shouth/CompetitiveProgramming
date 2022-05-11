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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < q; i++) {
        int l, r, q;
        cin >> l >> r >> q, l--, r--;
        for (int j = l; j <= r; j++) a[j] = q;
    }

    for (auto& e : a) cout << e << endl;
}
