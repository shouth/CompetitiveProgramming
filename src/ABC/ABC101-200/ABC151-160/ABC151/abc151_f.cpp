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

using point = pair<int, int>;

bool is_inside(point center, double radius, point p) {
    double dist = hypot(center.first - p.first, center.second - p.second);
    return dist <= radius;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for (auto& e : xy) cin >> e.first >> e.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

            }
        }
    }
}
