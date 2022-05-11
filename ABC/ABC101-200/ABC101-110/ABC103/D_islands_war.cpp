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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ab[b-1].push_back(a-1);
    }

    int bledge = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (const auto& e : ab[i]) {
            if (bledge < e) {
                bledge = i - 1;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
