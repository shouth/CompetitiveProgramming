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
    vector<int> a(n);
    for (auto& e : a) cin >> e, e--;
    vector<int> d(n, -1);
    for (int i = 0, j = 0; d[i] == -1; i = a[i], j++) d[i] = j;
    cout << d[1] << endl;
}
