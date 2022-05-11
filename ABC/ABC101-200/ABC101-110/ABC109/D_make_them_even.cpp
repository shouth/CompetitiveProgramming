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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (auto& e : a) for (auto& f : e) cin >> f;

    vector<pair<int, int>> from, to;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x + 1 < w; x++) {
            if (a[y][x] % 2) {
                a[y][x]--, a[y][x+1]++;
                from.emplace_back(y+1, x+1);
                to.emplace_back(y+1, x+2);
            }
        }
    }

    for (int y = 0; y + 1 < h; y++) {
        if (a[y][w-1] % 2) {
            a[y][w-1]--;
            a[y+1][w-1]++;
            from.emplace_back(y+1, w);
            to.emplace_back(y+2, w);
        }
    }

    cout << from.size() << endl;
    for (int i = 0; i < from.size(); i++) {
        cout << from[i].first << " " << from[i].second << " " << to[i].first << " " << to[i].second << endl;
    }
}
