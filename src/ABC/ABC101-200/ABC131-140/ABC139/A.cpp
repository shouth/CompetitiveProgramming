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
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) ans++;
    }

    cout << ans << endl;
}
