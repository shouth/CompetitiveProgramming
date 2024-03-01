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
    vector<vector<int>> m(h, vector<int>(w));
    for (auto& e : m) {
        for (auto& f : e) {
            cin >> f;
        }
    }
    for (auto& e : m) {
        for (auto& f : e) {
            int b;
            cin >> b;
            f -= b;
        }
    }


}
