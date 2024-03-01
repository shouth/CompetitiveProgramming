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
    string s;
    cin >> s;
    int c = 0, ans = 0;
    for (auto& e : s) {
        ans = max(ans, c += (e == 'I' ? 1 : -1));
    }
    cout << ans << endl;
}
