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
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        double s, e;
        cin >> s >> e;
        ans += s * e / 10;
    }

    cout << ans << endl;
}
