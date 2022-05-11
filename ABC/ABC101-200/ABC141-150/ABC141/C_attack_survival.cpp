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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> an(n, k-q);
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        an[a-1]++;
    }
    for (auto& e : an) cout << (e > 0 ? "Yes" : "No") << endl;
}
