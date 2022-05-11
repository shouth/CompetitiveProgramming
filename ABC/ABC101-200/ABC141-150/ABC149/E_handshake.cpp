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
    vector<int> a(n+1), acc(n+1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    partial_sum(a.begin(), a.end(), acc.begin());

    for (int i = 1, pc = 0; i <= n; i++) {
    }
}
