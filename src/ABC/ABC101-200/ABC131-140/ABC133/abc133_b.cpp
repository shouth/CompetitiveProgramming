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
    int n, d;
    cin >> n >> d;

    vector<vector<int>> x(n, vector<int>(d));
    for (auto& e : x) {
        for (auto& f : e) {
            cin >> f;
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double n = 0;
            for (int k = 0; k < d; k++) {
                n += pow(x[i][k] - x[j][k], 2);
            }

            double s = sqrt(n);
            if (s - (int) s == 0) ans++;
        }
    }

    cout << ans << endl;
}
