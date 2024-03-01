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
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        a.emplace_back(ai, i);
    }
    sort(begin(a), end(a), greater<>());
    for (auto& e : a) cout << e.second << endl;
}
