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
    string ans;
    for (auto& e : s) {
        if (e == 'B') {
            if (!ans.empty()) ans.pop_back();
        } else {
            ans += e;
        }
    }
    cout << ans << endl;
}
