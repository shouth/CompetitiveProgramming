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
    vector<vector<char>> c(h, vector<char>(w));
    for (auto& e : c) for (auto& f : e) cin >> f;

    for (auto& e : c) {
        for (auto& f : e) cout << f;
        cout << endl;
        for (auto& f : e) cout << f;
        cout << endl;
    }
}
