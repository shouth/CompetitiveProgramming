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
    int n, a, b;
    cin >> n >> a >> b;

    int c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int d;
        cin >> d, d = max(a, d), d = min(b, d);

        c += (s == "East" ? d : -d);
    }

    cout << (c == 0 ? "" : c > 0 ? "East " : "West ") << abs(c) << endl;
}
