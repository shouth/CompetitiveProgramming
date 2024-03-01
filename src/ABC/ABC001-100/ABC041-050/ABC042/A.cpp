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
    sort(begin(abc), end(abc));
    cout << (abc == vector<int> { 5, 5, 7 } ? "YES" : "NO") << endl;
}
