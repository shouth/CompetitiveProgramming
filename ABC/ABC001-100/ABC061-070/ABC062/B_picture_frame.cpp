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
    vector<string> a(h);
    for (auto& e : a) cin >> e;
    cout << string(w+2, '#') << endl;
    for (auto& e : a) cout << '#' << e << '#' << endl;
    cout << string(w+2, '#') << endl;
}
