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
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int c = 0;
        while (a % 2 == 0) a /= 2, c++;
        ans = min(ans, c);
    }

    cout << ans << endl;
}
