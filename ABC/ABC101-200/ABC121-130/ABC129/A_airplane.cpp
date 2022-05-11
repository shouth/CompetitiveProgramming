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
    vector<int> pqr(3);
    for (auto& e : pqr) cin >> e;

    cout << accumulate(pqr.begin(), pqr.end(), 0) - *max_element(pqr.begin(), pqr.end()) << endl;
}
