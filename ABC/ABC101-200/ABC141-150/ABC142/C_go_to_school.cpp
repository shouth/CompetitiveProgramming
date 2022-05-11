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
    vector<pair<int, int>> ap;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ap.emplace_back(a, i);
    }

    sort(begin(ap), end(ap));
    for (auto& e : ap) cout << e.second << " ";
}
