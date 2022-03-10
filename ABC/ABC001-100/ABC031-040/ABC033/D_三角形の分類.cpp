#include<bits/stdc++.h>
using namespace std;

constexpr double EPS = 1e-10;
const double PI = acos(-1);

int main() {
    int64_t n;
    cin >> n;
    vector<vector<int64_t>> xy(n, vector<int64_t>(2));
    for (auto& e : xy) cin >> e[0] >> e[1];
    
    int64_t lt90 = 0, eq90 = 0, gt90 = 0;
    for (int i = 0; i < n; i++) {
        vector<double> angles;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            auto t = atan2(xy[j][1] - xy[i][1], xy[j][0] - xy[i][0]);
            angles.push_back(t);
            angles.push_back(t + PI*2);
        }
        sort(begin(angles), end(angles));

        for (int64_t j = 0; j < n-1; j++) {
            eq90 += lower_bound(begin(angles), end(angles), PI/2 + EPS + angles[j])
                - lower_bound(begin(angles), end(angles), PI/2 - EPS + angles[j]);
            gt90 += lower_bound(begin(angles), end(angles), PI + EPS + angles[j])
                - lower_bound(begin(angles), end(angles), PI/2 + EPS + angles[j]);
        }
    }
    lt90 = n * (n-1) * (n-2) / 6 - eq90 - gt90;
    cout << lt90 << " " << eq90 << " " << gt90 << endl;
}
