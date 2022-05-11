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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int) s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) ans++;
    }
    cout << ans << endl;
}
