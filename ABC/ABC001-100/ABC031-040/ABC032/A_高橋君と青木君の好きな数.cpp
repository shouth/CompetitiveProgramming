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
    int a, b, n;
    cin >> a >> b >> n;
    int ablcm = a * b / __gcd(a, b);
    int ans = ablcm;
    while (ans < n) ans += ablcm;
    cout << ans << endl;
}
