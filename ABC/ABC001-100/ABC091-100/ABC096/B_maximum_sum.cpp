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
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    int k;
    cin >> k;
    sort(begin(abc), end(abc));
    cout << abc[0] + abc[1] + abc[2] * pow(2, k) << endl;;
}
