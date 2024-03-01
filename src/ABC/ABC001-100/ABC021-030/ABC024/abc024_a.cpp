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
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int s, t;
    cin >> s >> t;
    cout << a * s + b * t - (s + t) * c * (s + t >= k) << endl;
}
