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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n;
    cin >> n;
    vector<i32> v;
    for (i32 i = 0; i < n; i++) {
        i32 a;
        cin >> a;
        auto itr = upper_bound(begin(v), end(v), a, greater<>());
        if (itr == end(v)) v.push_back(a);
        else *itr = a;
    }

    cout << v.size() << endl;
}
